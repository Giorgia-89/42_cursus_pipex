/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:33:11 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/03 12:49:46 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)str)[i] = c;
		i++;
	}
	return (str);
}
/*
int main()
{
    char str[50];
    strcpy(str,"This is string.h library function\n");
    printf("%s", str);

    ft_memset(str,'$',7);
    printf("%s", str);

	strcpy(str,"This is string.h library function\n");
	printf("%s", str);

    memset(str,'$',7);
    printf("%s", str);

}*/