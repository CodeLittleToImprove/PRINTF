/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idea_of_ft_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:57:07 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/01/24 11:38:36 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf ( const  char *format, ...)
{
	va_list	arg;
	int		current_index; 
	int		c_printed;

	current_index = 0;
	c_printed = 0;
	va_start(arg, format); 
	// va_start takes 2 arguments the va_list and the name of last required argument

	/* 	* In this loop, the idea is to go through the entire string contained in format until the end, 	* which in this case is a '\0' 	*/
	while (format[current_index])
	{ 
	/*         * Here I check if the character '% ' exists, if it exists,
	I check * if any of the characters passed next are printf flags with the function * ➡️ ft_strchr()⬅️
	if you got this far, you know how it works*/
		if (format[current_index] == '%' && ft_strchr( "cspdiuxX%" , format[current_index + 1 ]))
		{
		c_printed += ft_printf_arg(format, current_index, arg); 
		current_index++; 
		return (0);
		}
		/*         * If not found, the character will be printed and added to "c_printed" which is the         * control of how many characters were printed.         */
		else
		c_printed += ft_putchar(format[current_index]);
		current_index++;
	}
	va_end(arg);
	return (c_printed);
}
int	main()
{
	int		age = 30;
	char	name[] = "John Smith";

	ft_printf("My name is %s and I am %d years old.", name, age);
	return 0;
}


