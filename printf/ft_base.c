/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:14:31 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/25 13:06:41 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int n)
{
	long int	quotient;
	long int	remainder;
	char		deca[50];
	int			i;
	int			len;

	quotient = n;
	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (quotient != 0)
	{
		remainder = quotient % 10;
		if (remainder < 10)
			deca[i++] = remainder + 48;
		else
			deca[i++] = remainder + 55;
		quotient = quotient / 10;
	}
	len = i;
	while (i--)
		write(1, &deca[i], 1);
	return (len);
}

int	ft_lowerhex(unsigned int n)
{
	long int	quotient;
	long int	remainder;
	int			i;
	int			len;
	char		hexa[50];

	quotient = n;
	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexa[i++] = remainder + '0';
		else if (remainder < 16)
			hexa[i++] = remainder + 87;
		quotient = quotient / 16;
	}
	len = i;
	while (i--)
		write(1, &hexa[i], 1);
	return (len);
}

int	ft_upperhex(unsigned int n)
{
	long int	quotient;
	long int	remainder;
	int			i;
	int			len;
	char		hexa[50];

	quotient = n;
	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexa[i++] = remainder + 48;
		else
			hexa[i++] = remainder + 55;
		quotient = quotient / 16;
	}
	len = i;
	while (i--)
		write(1, &hexa[i], 1);
	return (len);
}

//main function takes the int and the base (fed from ft_printf) and checks
//whether we need to transform to base 10 or 16, then sends n to the 
//corresponding function. 
int	ft_base(unsigned int n, char *base)
{
	int	res;

	res = 0;
	if (ft_strcmp(base, "0123456789") == 1)
		res = ft_unsigned(n);
	else if (ft_strcmp(base, "0123456789abcdef") == 1)
		res = ft_lowerhex(n);
	else if (ft_strcmp(base, "0123456789ABCDEF") == 1)
		res = ft_upperhex(n);
	return (res);
}
