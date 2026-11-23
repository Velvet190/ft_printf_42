/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:33:50 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/23 16:48:26 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	check_conv(const char *form, int i, va_list args)
{
	int len;
	i++;
	if (form[i] == '\0' || form[i] == '%')
		return(-1);
	if (form[i] == 'c' || form[i] == 's' || form[i] == 'd')
	{
		len = print_arg(form[i], args);
		i += len;
		return(i);
	}
	return(-1);
}