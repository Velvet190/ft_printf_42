/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 01:06:41 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/23 17:39:52 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		i;
	int		len;
	i = 0;
	len = 0;
	va_start(args, form);
	while (form[i])
	{
		if (form[i] == '%' && form[i + 1])
		{
			check_conv(form, i, args);
			i += 2;
		}
		else
		{
			write(1, &form[i], 1);
			i++;
		}
	}
	va_end(args);
	return (len);
}







#include <stdio.h>

int	main(void)
{
    //printf("Ma fonction retourne : %d", ft_printf("Bonjour %s", "Velvet\n"));
    //printf("Bonjour %s, XD, C'est %s, avec un grand %c, qui a %d cadeaux.", "Velvet", "Julie", 'J', 67);
	ft_printf("Bonjour %s\n", "Velvet");
	ft_printf("char : %c\n", 'A');
	ft_printf("int : %d\n", 42);
	ft_printf("neg : %d\n", -42);
	ft_printf("min : %d\n", -2147483648);
	ft_printf("null : %s\n", NULL);
}