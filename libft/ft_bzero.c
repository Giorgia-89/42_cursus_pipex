/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:03:53 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/03 13:23:38 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*c;
	size_t	i;

	c = s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}
/* all of the above could have been done
easily with ft_memset:
void ft_bzero(void * s, size_t n)
{
    ft_memset(s, '\0', n)
}

int main()
{
    char s[100] = "aaaaa";
	char sbis[100] = "aaaaa";

    printf("Test de ft_bzero :\n");
	strcpy(sbis, s);
	bzero(s, 3);
	ft_bzero(sbis, 3);
	int		i;
	i = 0;
	while (i < 5 && s[i] == sbis[i])
		i++;
	if (i == 5)
		printf("OK\n");
	else
		printf("Failed : expected [%c][%c][%c][%c][%c],\
		got [%c][%c][%c][%c][%c].\n", s[0], s[1], s[2],\
		s[3], s[4], sbis[0], sbis[1], sbis[2], sbis[3], sbis[4]);
    return(0);
}*/
