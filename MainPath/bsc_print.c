/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsc_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 18:13:06 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/27 20:57:11 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	bsc_print(const char *form, va_list args)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (form[i])
	{
		if (form[i] == '%' && !form[i + 1])
			return (-1);
		if (form[i] == '%')
		{
			i++;
			len += arg_print(form[i], args);
			i++;
		}
		else
		{
			len += write(1, &form[i], 1);
			i++;
		}
	}
	return (len);
}
