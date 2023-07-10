/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:06:31 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/06/17 11:34:44 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//this function takes as arguments two fds and closes them.
void	close_fds(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

//this function prints an error message and returns. The args include 
//the error code n and an optional string to print an invalid command
void	print_err(int n, char *cmd)
{
	if (n == 0)
		ft_putstr_fd("\033[31mIncorrect number of arguments\n\e[0m", 2);
	else if (n == 2)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putchar_fd('\n', 2);
		return ;
	}
	else
		ft_putstr_fd("\033[31mInvalid arguments\n\e[0m", 2);
	ft_putstr_fd("Correct format is ./pipex <infile> <cmd1>\
 <cmd2> <outfile>\n", 2);
	ft_putstr_fd("Handle more commands via ./pipex_bonus\n", 2);
}

//this function takes as arguments the command to be executed and envp, which 
//are sent by the parent/child process. It split the commands before calling
//find path, and frees memory if the path is not found. Finally,
//it executes the command and its args using execve. 
int	execute_command(char *argv, char **envp)
{
	char	**cmds;
	char	*cmdpath;

	cmds = ft_split(argv, ' ');
	if (cmds[0] == NULL || check_arg(cmds[0]) == -1)
	{
		print_err(1, NULL);
		free(cmds);
		return (-2);
	}
	if (check_slash(cmds) == -2)
		return (-2);
	cmdpath = find_path(cmds[0], envp);
	if (check_cmdpath(cmds, cmdpath) == -2)
		return (-2);
	if (execve(cmdpath, cmds, envp) == -1)
		return (-2);
	free(cmdpath);
	return (0);
}

//this function takes as arguments the command and envp and
//iteratively looks through the envp PATHS to search for the 
//one containing the command. It checks access permissions 
//before returning the path. Memory for paths is cleared 
//before exiting
char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (NULL);
}
