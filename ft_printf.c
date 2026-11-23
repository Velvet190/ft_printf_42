/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 01:06:41 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/23 16:55:05 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		i;
	i = 0;
	va_start(args, form);
	while (form[i])
	{
		while (form[i] != '%')
		{
			write(1, &form[i], 1);
			i++;
		}
		i = check_conv(form, i, args);
	}
    return(i);
}







#include <stdio.h>

int	main(void)
{
    ft_printf("Bonjour %s", "Velvet\n");
    //printf("Bonjour %s", "Velvet\n");
}