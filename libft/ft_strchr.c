/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:52:52 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/09 13:55:11 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int i)
{
	while (*s != '\0' && (unsigned char)i != *s)
		s++;
	if ((unsigned char)i == *s)
		return ((char *)s);
	return (0);
}

/*int main()
{
	const char s[] = "teste";
	const char c = 357: 'e';
	char *p;

	p = strchr(s, 't' + 256);
	printf("String starting from %c is: %s\n", c, p);
	p = ft_strchr(s, 't' + 256);
	printf("String starting from %c is: %s\n", c, p);

	return(0);
}*/