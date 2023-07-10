/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:49:26 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/04 12:44:38 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;
	char	*s;
	size_t	i;

	s = (char *)src;
	temp = (char *)dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n-- > 0)
			temp[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			temp[i] = s[i];
			i++;
		}
	}
	dest = temp;
	return (dest);
}
/*this function is very similar to memcpy, but better in the case of overlapping
memory addressess for the src and dest strings. Main difference is that we
first check to see if dest string is greater than source. if so. we copy src to
dest starting from the last element of src n, until n > 0.
Otherwise, we copy from src to dest until i < n /*/
/*int main()
{
    char str1[] = "Geeks"; // Array of size 100
    char str2[] = "Quiz"; // Array of size 5
  
    puts("str1 before memmove ");
    puts(str1);
  
    // Copies contents of str2 to sr1 
    memmove(str1, str2, 1);
  
    puts("\nstr1 after memmove ");
    puts(str1);

	char str3[] = "Geeks"; // Array of size 100
    char str4[] = "Quiz"; // Array of size 5

	    // Copies contents of str2 to sr1 
    ft_memmove(str3, str4, 1);
  
    puts("\nstr1 after ft_memmove ");
    puts(str3);
    return 0;
}*/