/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 01:06:41 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/27 21:15:52 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	bad_end(const char *form)
{
	int	i;

	i = 0;
	while (form[i])
	{
		if (form[i] == '%')
		{
			if (!form[i + 1])
				return (1);
			i++;
		}
		i++;
	}
	return (0);
}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		len;

	len = 0;
	if (!form || bad_end(form))
		return (-1);
	if (!chk_prc((char *)form))
		return (ft_putstr((char *)form));
	else
	{
		va_start(args, form);
		len = bsc_print(form, args);
	}
	va_end(args);
	return (len);
}
