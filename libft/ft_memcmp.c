/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:49:38 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/03 12:46:23 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//note MUST typecast parameters when allocating them to pointers
/*tfunction returns different values from memcmp.*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*ptr1;
	unsigned char		*ptr2;
	size_t				i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	const char s[] = "HELLO!world";
	const char c[] = "HEllo ";
	long unsigned int size;
	int res;

	size = 3;
	res = memcmp(s, c, size);
	printf(" size %ld: result is %d\n", size, res);
	res = ft_memcmp(s, c, size);
	printf("My result is %d\n", res);
	size = 5;
	res = memcmp(s, c, size);
	printf("size %ld: result is %d\n", size, res);
	res = ft_memcmp(s, c, size);
	printf("My result is %d\n", res);
	return(0);
}*/
