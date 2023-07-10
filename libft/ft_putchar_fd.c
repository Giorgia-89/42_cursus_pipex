/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:04:39 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/14 15:02:30 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*this funtion takes a char c and a file descriptor on which to write, fd.
outputs the char c to the given file descriptor. Returns nothing.
Allowed functions: write */
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
