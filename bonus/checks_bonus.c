/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:10:52 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/06/19 10:02:29 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_argc(int argc)
{
	if (argc < 6)
	{
		print_err(0, NULL);
		exit(1);
	}
	return ;
}

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

int	check_cmdpath(char **cmds, char *cmdpath)
{
	int	i;

	i = 0;
	i = -1;
	if (!cmdpath)
	{
		print_err(3, cmds[0]);
		while (cmds[++i])
			free(cmds[i]);
		free(cmds);
		return (-2);
	}
	return (0);
}
