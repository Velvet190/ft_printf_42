/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:33:28 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/27 14:37:24 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	arg_print(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar((char)va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_adrprt(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		len += ft_itoa_signd(va_arg(args, int), 10);
	else if (c == 'u')
		len += ft_itoa_unsignd(va_arg(args, unsigned int), 10);
	else if (c == 'x')
		len += ft_itoa_unsignd(va_arg(args, unsigned long int), 16);
	else if (c == 'X')
		len += ft_itoa_unsigndmajx(va_arg(args, unsigned long int), 16);
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}
