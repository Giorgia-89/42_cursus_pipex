/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:32:59 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/09 11:05:27 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*source;
	char		*destin;
	size_t		i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	destin = (char *)dest;
	source = (char *)src;
	while (i < n)
	{
		destin[i] = source[i];
		i++;
	}
	return (destin);
}
/*
int		main(void)
{
	char s[100] = "aaaaa";
	char sbis[100] = "aaaaa";
	printf("Test de ft_memcpy :\n");
	strcpy(sbis, s);
	if (!strcmp(memcpy(s, "source", 3), ft_memcpy(sbis, "source", 3)) && \
	 !strcmp(memcpy(s, "2emesource", 8), ft_memcpy(sbis, "2emesource", 8)))
		printf("OK\n");
	else
		printf("Failed : expected '%s', got '%s'.\n", s, sbis);
	return(0);
}*/