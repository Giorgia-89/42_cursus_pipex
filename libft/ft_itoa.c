/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:35:15 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/14 14:40:37 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*this function takes an integer, allocates with malloc and returns a string
representing the integer received as an argument. Negative numbers must be 
handled*/
#include "libft.h"

static int	abs_num(int n)
{
	if (n < 0)
		n = (n * -1);
	return (n);
}

static int	get_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		++len;
	while (nbr != 0)
	{
		++len;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = get_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	else if (n == 0)
		res[0] = '0';
	res[len] = '\0';
	len--;
	while (n != 0)
	{
		res[len] = abs_num(n % 10) + '0';
		n = n / 10;
		len --;
	}
	return (res);
}
/*
int main()
{
	int n =-23445;

	printf("number is %s", ft_itoa(n));
	return (0);
}*/