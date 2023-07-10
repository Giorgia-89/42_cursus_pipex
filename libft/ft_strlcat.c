/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:43:42 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/04 14:02:15 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	dstsize;
	size_t	srcsize;
	size_t	i;

	dstsize = 0;
	srcsize = 0;
	i = 0;
	while (dst[dstsize])
		dstsize++;
	while (src[srcsize])
		srcsize++;
	if (size < dstsize + 1)
		return (size + srcsize);
	if (size > dstsize + 1)
	{
		while (src[i] && (dstsize + 1 + i < size))
		{
			dst[dstsize + i] = src[i];
			i++;
		}
		dst[dstsize + i] = '\0';
	}
	return (dstsize + srcsize);
}
/*
int main()
{
    char first[] = "This is ";
    char last[] = "a string";
    int r;
    int size = 3;
    char buffer[size];

    strcpy(buffer,first);
    r = ft_strlcat(buffer,last,size);

    puts(buffer);
    printf("Value returned: %d\n",r);
    if( r > size )
        puts("String truncated");
    else
        puts("String was fully copied");
    return(0);
}*/
/*
int main()
{
    char first[14] = 'a';
    char last[] = "lorem ipsum dolor sit amet";
    int r;
    int size = 15;
    char buffer[size];

    strcpy(buffer,first);
    r = ft_strlcat(buffer,last,size);

    puts(buffer);
    printf("Value returned: %d\n",r);
    if( r > size )
        puts("String truncated");
    else
        puts("String was fully copied");
    return(0);
}*/