/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:21:47 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/11 17:04:16 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This function returns a pointer to a new string which is a duplicate of 
the string s. Memory for the new string is allocated with malloc */
#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*dup;
	int		len;
	int		j;

	len = 0;
	j = 0;
	while (s[len])
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (s[j])
	{
		dup[j] = s[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}
/*
void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main()
{
	char	str[] = "lorem ipsum dolor sit amet";
	char	*str_dup;

	if (!(str_dup = ft_strdup(str)))
		ft_print_result("NULL");
	else
		ft_print_result(str_dup);
	if (str_dup == str)
		ft_print_result("\nstr_dup's adress == str's adress");
	return (0);	
}
*/