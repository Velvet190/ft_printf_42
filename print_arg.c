/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:33:28 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/23 17:50:52 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <unistd.h>

int print_arg(char c, va_list args)
{
    int     i;
    char    *str;

    i = 0;
    if (c == 'c')
    {
        char ch = va_arg(args, int);
        write(1, &ch, 1);
    }
    else if (c == 's')
    {
        str = va_arg(args, char *);
        if (!str)
            str = "(null)";
        while (str[i])
            write(1, &str[i++], 1);
    }
    else if (c == 'd' || c == 'i')
    {
        str = ft_itoa(va_arg(args, int));
        while (str[i])
            write(1, &str[i++], 1);
        free(str);
    }
    return (i);
}