/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_helpers_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:19:23 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/06/19 10:02:38 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_fds(int fd)
{
	if (fd < 0)
	{
		perror("error");
		exit(1);
	}
}

int	check_and_close_fds(int fd_check, int fd_close)
{
	if (fd_check < 0)
	{
		perror("fd error");
		close(fd_close);
		return (-2);
	}
	return (0);
}

void	close_fds(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}
