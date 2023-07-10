/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:19:26 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/14 15:18:10 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*this function takes a string s and an int file descriptor fd, on which to 
write. outputs the string s to the given file descriptor, followed
by a new line. returns nothing.
allowed function: write*/
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
