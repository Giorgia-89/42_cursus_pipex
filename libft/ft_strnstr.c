/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:59:30 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/04 14:46:49 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function locates the first occurence of the string to_find in the str,
searching up to n characters. 
if to_find is an empty string, return str.
if to_find is not present in str, return NULL
if to_find is present, return a pointer to the first char of the first instance.
*/
#include "libft.h"

char	*ft_strnstr(char *str, char *tofind, size_t len)
{
	size_t	s;
	size_t	f;

	s = 0;
	f = 0;
	if (tofind[f] == 0)
		return (str);
	while (str[s] && s < len)
	{
		f = 0;
		while (str[s + f] == tofind[f] && s + f < len)
		{
			if (tofind[f + 1] == '\0')
				return (&str[s]);
			f++;
		}
		s++;
	}
	return (0);
}
/*
int main()
{
	char s[] = "lorem ipsum dolor sit amet";
	char c[] = "dolor";
	int size;
	char *res;

	size = 15;
	res = ft_strnstr(s, c, size);
	printf("My result: Substring is at %s\n", res);
	return(0);
}*/