/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:44:04 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/04 14:26:16 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while ((i < n - 1) && s1[i] && s2[i] && (s1[i] == s2[i]))
			i++;
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
/*
int main()
{
	const char s[] = "test\200";
	const char c[] = "test\0";
	int size;
	int res;

	size = 6;
	res = strncmp(s, c, size);
	printf("result is %d\n", res);
	res = ft_strncmp(s, c, size);
	printf("My result is %d\n", res);
	return(0);
}*/