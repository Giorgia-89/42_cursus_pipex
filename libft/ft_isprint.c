/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:22 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/09 11:07:56 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
int main()
{
    int c = 125;
    int d = '\n';

    printf("My function: Result when a printable character %c \
	is passed to isprint(): %d \n", c, ft_isprint(c));
    printf("My function: Result when a control character %c \
	 is passed to isprint(): %d \n", d, ft_isprint(d));
    return(0);
}*/