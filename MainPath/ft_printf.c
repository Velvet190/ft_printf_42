/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 01:06:41 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/26 18:50:54 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../ft_printf/ft_printf.h"

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		i;
	int		len;
	i = 0;
	len = 0;
	va_start(args, form);
	if (!chk_prc(form))
		return(ft_putstr(form));
	else
		len = bsc_print(form, args);
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