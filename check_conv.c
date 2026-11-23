/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:33:50 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/23 17:47:19 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int check_conv(const char *form, int i, va_list args)
{
    char c;

    c = form[i + 1];
    if (c == 'c' || c == 's' || c == 'd' || c == 'p' || c == 'i' || c == 'u' || c == '%')
        return (print_arg(c, args));
    return (0);
}