/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:24:20 by giorgia           #+#    #+#             */
/*   Updated: 2022/11/25 11:37:11 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long n)
{
	char		str[25];
	char		*hexo;
	int			i;
	int			len;

	i = 0;
	hexo = "0123456789abcdef";
	len = 0;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (len + 5);
	}
	write(1, "0x", 2);
	len += 2;
	while (n != 0)
	{
		str[i] = hexo[n % 16];
		n /= 16;
		i++;
	}
	len += i;
	while (i--)
		write(1, &str[i], 1);
	return (len);
}
