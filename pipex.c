/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:52:31 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/06/17 11:30:19 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//this function is called at the start of the program to perform initial checks
//and open the in and outfile.
//If less than two commands are provided, an error message is printed to stdout
//and the program exits.
//It then tries to open first the infile and then the outfile. if either does
//not exist, it is closed, an error is printed and the program exits. Otherwise,
//infile is closed and fd for the outfile is returned to be used in the main and
//parent process
int	checks(int argc, char **argv)
{
	int	fd_in;
	int	fd_out;

	if (argc != 5)
	{
		print_err(0, NULL);
		exit(1);
	}
	fd_in = open(argv[1], O_RDONLY);
	check_fds(fd_in);
	close(fd_in);
	fd_out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	check_fds(fd_out);
	return (fd_out);
}

//In the parent process, dup2 is used to redirect stdin to the reading end of 
//the pipe. The outfile is opened and allocated to fd_out; dup2 is used to 
//redirect the output from stdout to the outfile. Finally, the command is
//executed
void	parent_process(char **argv, char **envp, int *fd, int fd_out)
{
	int	fd_dup[2];

	close(fd[1]);
	fd_dup[0] = dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	if (fd_dup[0] < 0)
	{
		close_fds(fd[0], fd_out);
		exit(1);
	}
	fd_dup[1] = dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	check_fds(fd_dup[1]);
	if (execute_command(argv[3], envp) == -2)
	{
		close_fds(fd_dup[1], fd_dup[0]);
		exit(1);
	}
	close_fds(fd_dup[1], fd_dup[0]);
	exit(0);
}

//In the child process, the infile is opened and allocated to fd_in. 
//dup2 is used to redirect stdin to the infile, and to redirect the output 
//from stdout to the writing end of the pipe. Finally, the command is
//executed
void	child_process(char **argv, char **envp, int *fd)
{
	int	fd_in;
	int	fd_dup[2];

	close(fd[0]);
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
	{
		perror("error");
		close(fd[1]);
		exit(3);
	}
	fd_dup[0] = dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	check_and_close_fds(fd_dup[0], fd[1]);
	fd_dup[1] = dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (execute_command(argv[2], envp) == -2)
	{
		close_fds(fd_dup[0], fd_dup[1]);
		exit(1);
	}
	close_fds(fd_dup[0], fd_dup[1]);
	exit(0);
}

//In the main, we initialise fds for pipe and pid for child process.
// Open the pipe, then fork. 
//if pid == 0, we are in the child process - execute the first command
//otherwise, we are in the parent process
int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	fd_out;

	fd_out = checks(argc, argv);
	if (pipe(fd) < 0)
		exit(EXIT_FAILURE);
	pid1 = fork();
	if (pid1 < 0)
		exit(EXIT_FAILURE);
	else if (pid1 == 0)
	{
		close_fds(fd[0], fd_out);
		child_process(argv, envp, fd);
	}
	else
	{
		close(fd[1]);
		parent_process(argv, envp, fd, fd_out);
	}
	waitpid(pid1, NULL, 0);
	close_fds(fd[0], fd[1]);
	exit(0);
}
