/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:17:37 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/09 10:56:01 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(unsigned char c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}
/*
int     main(void)
{
        printf("%d\n", ft_isalnum('1'));
        printf("%d\n", ft_isalnum('j'));
        printf("%d\n", ft_isalnum('J'));
        printf("%d\n", ft_isalnum('.'));

        return (0);
}*/