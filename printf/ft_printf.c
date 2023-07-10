/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:57:50 by giorgia           #+#    #+#             */
/*   Updated: 2022/11/24 11:56:16 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//authorised functions:
//malloc, free, write, 
//va_start, va_copy, va_arg, va_end

//first function checks whether the current char is one of the conversion
//specifiers
int	ft_check(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'\
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

//second function is to count the number of written chars, and to send the
//current chars to the subfunctions for conversions if it satisfies
//the ft_check (i.e., if it's one of the specifiers). 
int	ft_convert(char conv, va_list args)
{
	int	count;

	count = 0;
	if (conv == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (conv == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (conv == 'p')
		count += ft_pointer(va_arg(args, unsigned long));
	else if (conv == 'd' || conv == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (conv == 'u')
		count += ft_base(va_arg(args, unsigned int), "0123456789");
	else if (conv == 'x')
		count += ft_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (conv == 'X')
		count += ft_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (conv == '%')
		count += ft_putchar('%');
	return (count);
}

//third function is to start writing the chars of the first arg to output
//and count the number of written chars
int	ft_start(const char *format, va_list args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (!format)
			return (count);
		if (format[i] == '%')
		{
			i++;
			if (ft_check(format[i]))
				count += ft_convert(format[i], args);
			else
				return (count);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	return (count);
}

//main printf function initialises in int to start writing the chars
//of the first arg., launches all the auxiliary functions and returns
//tot n of chars written 
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	va_start(args, str);
	i = ft_start(str, args);
	va_end(args);
	return (i);
}
