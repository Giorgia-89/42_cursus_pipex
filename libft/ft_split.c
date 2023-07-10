/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:25:33 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/06/06 15:20:20 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* takes a string s and a char c, 
Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.
STEPS needed:
- count words;
- write words;
- split;
*/

static int	count_words(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i + 1] == c || !str[i + 1]) && (str[i] != c || !str[i]))
			count++;
		i++;
	}
	return (count);
}

static char	*write_word(char const *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)(malloc(sizeof(char) * (finish - start + 1)));
	if (!word)
		return (NULL);
	while (start < finish)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		index;

	tab = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		index = i;
		if (s[i] != '\0')
		{
			while (s[i] && s[i] != c)
				i++;
			tab[j] = write_word(s, index, i);
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
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

int main()
{
	char **tab;
	int i;
	//char c;

	//c = ' ';
	tab = ft_split("lorem ipsum dolor sit amet,.!", '!');
	i = 0;
	while (tab[i] != NULL)
	{
		ft_print_result(tab[i]);
		write(1, "\n", 1);
		i++;
	}
	return(0);
}
*/