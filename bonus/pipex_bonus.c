/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:52:31 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/06/19 10:26:13 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	open_infile(char **argv)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
	{
		perror("error");
		exit(1);
	}
	return (fd_in);
}

void	main_process(char *cmd, char **envp)
{
	pid_t	pid;
	int		*fd;
	int		fd_dup;

	fd = malloc(sizeof(int) * 2);
	if (pipe(fd) < 0)
		exit (1);
	pid = fork();
	if (pid == -1)
		exit (1);
	if (pid == 0)
	{
		close(fd[0]);
		child_process(fd, cmd, envp);
	}
	else
	{
		close(fd[1]);
		fd_dup = dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		check_fds(fd_dup);
	}
	close_fds(fd[1], fd[0]);
	free(fd);
}

void	child_process(int *fd, char *cmd, char **envp)
{
	int	fd_dup;

	close(fd[0]);
	fd_dup = dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (fd_dup < 0)
	{
		perror("dup failed in child process");
		exit(1);
	}
	if (execute_command(cmd, envp) == -2)
	{
		free(fd);
		close(fd_dup);
		exit(1);
	}
	close(fd_dup);
}

void	parent_process(int argc, char **argv, int *fd_dup, char **envp)
{
	if (execute_command(argv[argc - 2], envp) == -2)
	{
		close(fd_dup[0]);
		close(fd_dup[1]);
		exit(1);
	}
}

//This function initialises fds for infile and outfile and opens the files.
//dup2 is used to redirect stdin of the first command to 
//fd_in. I is intialised to be the first command (argv[2]). 
//The child process is called until there is only one command left. Finally,
//dup2 is used to redirect stdout to the outfile before executing the command
int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fd_in;
	int	fd_out;
	int	fd_dup[2];

	check_argc(argc);
	i = 2;
	fd_in = open_infile(argv);
	check_fds(fd_in);
	fd_dup[0] = dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	check_fds(fd_dup[0]);
	while (i < argc - 2)
		main_process(argv[i++], envp);
	fd_out = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	check_and_close_fds(fd_out, fd_dup[0]);
	fd_dup[1] = dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	if (check_and_close_fds(fd_dup[1], fd_dup[0]) == -2)
		exit(1);
	parent_process(argc, argv, fd_dup, envp);
	close_fds(fd_dup[0], fd_dup[1]);
	exit(0);
}
