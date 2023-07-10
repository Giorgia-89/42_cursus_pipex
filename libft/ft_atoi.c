/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:00:50 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/09 13:31:50 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
/*
int main(void)
{
	char str1[] = "123";
	char str2[] = "12a34";
	char str3[] = "     45";
	char str4[] = "-45+++---";
	char str5[] = "+++-45  ";

	printf("My result: %d\n", ft_atoi(str1));
	printf("ATOI: %d\n", atoi(str1));
	printf("My result: %d\n", ft_atoi(str2));
	printf("ATOI: %d\n", atoi(str2));
	printf("My result: %d\n", ft_atoi(str3));
	printf("ATOI: %d\n", atoi(str3));
	printf("My result: %d\n", ft_atoi(str4));
	printf("ATOI: %d\n", atoi(str4));
	printf("My result: %d\n", ft_atoi(str5));
	printf("ATOI: %d\n", atoi(str5));

	return (0);
}*/
