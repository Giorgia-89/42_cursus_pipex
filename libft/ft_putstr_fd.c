/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:15:02 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/14 15:19:10 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*this function takes a string s and an int file descriptor, fd, on which to 
write.  Outputs the string s to the given file descriptor. Returns nothing
allowed functions: write. */
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}
