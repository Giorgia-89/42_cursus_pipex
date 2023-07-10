/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:34:31 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/09 13:57:29 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}

/*
int main()
{
	const char s[] = "Hello world";
	const char c = '\0';
	char *p;

	p = strrchr(s, c);
	printf("String starting from %c is: %s\n", c, p);
	p = ft_strrchr(s, c);
	printf("String starting from %c is: %s\n", c, p);
	return(0);
}*/