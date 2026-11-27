/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 01:06:41 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/27 20:37:13 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		len;

	len = 0;
	if (!form)
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
