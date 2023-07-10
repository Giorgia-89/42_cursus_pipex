/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:53:14 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/11 17:07:04 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string. 

First need one function to see if char is in s1,
and if so, return 1.

Then, in ft_strtrim, if in_set == 1, advance the start.
Go to end of s1 - 1 and if in_set == 1, reduce the end.
Allocate enough memory for sizeof(char) * end - start + 1
(to account for null)
finally, copy into new str the contents of s1 from start
to end

*/
static int	char_in_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && char_in_set(s1[start], set))
		start++;
	while ((end > start) && char_in_set(s1[end - 1], set))
		end--;
	str = malloc(sizeof(char) * (end - start + 1));
	if (str == NULL)
		return (str);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
/*
int main()
{
	char s1[] = "Hello world";
	char set[] = "Herd";
	
	printf("Trimmed string is %s\n", ft_strtrim(s1, set));
	return(0);
}*/