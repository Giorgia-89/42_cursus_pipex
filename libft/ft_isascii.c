/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:28:46 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/09 11:02:33 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
char the_chars[] = { 'A', 0x80, 'Z' };

#define SIZE sizeof( the_chars ) / sizeof( char )

int main( void )
{
    long unsigned int i;

    for( i = 0; i < SIZE; i++ ) {
        if( ft_isascii( (unsigned)the_chars[i] ) ) {
            printf( "Char %c is an ASCII character\n",
                the_chars[i] );
        } else {
            printf( "Char %c is not an ASCII character\n",
                the_chars[i] );
        }
    }
    
    return EXIT_SUCCESS;
}*/