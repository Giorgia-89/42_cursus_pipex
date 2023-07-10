/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:44:34 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/06/19 09:55:59 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//this function takes as argument an fd and checks whether it was 
//created successfully. If not, it closes it and exits the program. 
void	check_fds(int fd)
{
	if (fd < 0)
	{
		perror("error");
		exit(1);
	}
}

//this function takes as argument an fd to check whether it was 
//created successfully, and another fd whose state depends on the 
//first one. If the first fd was not created, an error message is printed, the 
//second fd is closed and the program exits with 1. 
void	check_and_close_fds(int fd_check, int fd_close)
{
	if (fd_check < 0)
	{
		perror("fd error");
		close(fd_close);
		exit(1);
	}
}

//this function checks if the arguments are alphabetical chars. It
//returns 0 if they are all chars, -1 if not
int	check_arg(char *cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		if (ft_isalpha(cmds[i] == 0))
			return (-1);
		i++;
	}
	return (0);
}

//this function checks whether the first part of each command includes
//a slash, and if so, it prints an error message and returns -2 
int	check_slash(char **cmds)
{
	int	i;

	if (ft_strrchr(cmds[0], '/') != 0)
	{	
		ft_putstr_fd("permission denied: /\n", 2);
		i = -1;
		while (cmds[++i])
			free(cmds[i]);
		free(cmds);
		return (-2);
	}
	return (0);
}

//this function checks whether the command path was succesfully
//found. If not, it frees memory for the commands and returns -2
int	check_cmdpath(char **cmds, char *cmdpath)
{
	int	i;

	i = 0;
	i = -1;
	if (!cmdpath)
	{
		print_err(2, cmds[0]);
		while (cmds[++i])
			free(cmds[i]);
		free(cmds);
		return (-2);
	}
	return (0);
}
