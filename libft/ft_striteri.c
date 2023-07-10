/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:53:16 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/09 11:20:05 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*this function takes a string s, on which to iterate, and a function f,
to be applied to each char. 
Applies funciton f to each char of string s, passing its index as first
argument. Each char is passed by address to f to be modified if 
necessary.
does not return anything */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
