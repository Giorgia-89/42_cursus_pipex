/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:46:45 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/04 14:36:48 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The memchr() function scans the initial n bytes of the memory area
pointed to by s for the first instance of c.  Both c and the bytes of
the memory area pointed to by s are interpreted as unsigned char.
return a pointer to the matching byte or NULL if the character does 
not occur in the given memory area.*/

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	ch;
	size_t			i;

	ptr = (unsigned char *)str;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == ch)
			return (&ptr[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	//const char s[] = "Hello world";
	//const char c = 'd';
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	//char *p = tab;
	size_t n = 7;

	printf("%s", (char *)ft_memchr(tab, -1, n));
	return(0);
}*/