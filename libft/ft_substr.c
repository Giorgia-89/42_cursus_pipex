/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:38:22 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/09 14:08:51 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* this function takes a string (s), an integer start and a size_t 
len.Allocates with malloc and returns a substring from the string s,
or NULL if the allocation fails.
The substring begins at index start and is of max size len*/
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char));
		*str = 0;
		return (str);
	}
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
	{
		str[j++] = s[i++];
	}
	str[j] = '\0';
	return (str);
}
/*
int main()
{
	char s[] = "Hola";
	int size;
	int start;

	start = 0;
	size = 4;
	printf("My result: Substring is %s\n", ft_substr(s, start, size));
	return(0);
}*/