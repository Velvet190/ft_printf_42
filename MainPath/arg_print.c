/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:33:28 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/26 19:04:17 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "../ft_printf/ft_printf.h"
#include <unistd.h>

int arg_print(char c, va_list args)
{
    int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar((char)va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_putptr(va_arg(args, void *));
	// else if (c == 'd' || c == 'i')
	// 	len += ft_putnbr_base_signed(va_arg(args, int), "0123456789");
	// else if (c == 'u')
	// 	len += ft_putnbr_base_unsigned(va_arg(args, unsigned int),
	// 			"0123456789");
	// else if (c == 'x')
	// 	len += ft_putnbr_base_unsigned((unsigned long int)va_arg(args,
	// 				unsigned int), "0123456789abcdef");
	// else if (c == 'X')
	// 	len += ft_putnbr_base_unsigned(va_arg(args, unsigned int),
	// 			"0123456789ABCDEF");
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}