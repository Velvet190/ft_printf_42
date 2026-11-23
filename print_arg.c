/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:33:28 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/23 16:38:30 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include <unistd.h>

int print_arg(char c, va_list args)
{
	int i= 0;
	if (c == 'c')
	{
        int chr = va_arg(args, int);
        write(1, &chr, 1);
        i++;
	}
	else if (c == 's')
    {
        char *chr = va_arg(args, char *);
        while (chr[i])
        {
            write(1, &chr[i], 1);
            i++;
        }
    }
	else if (c == 'd')
    {
        int chr = va_arg(args, int);
        write(1, &chr, 1);
        i++;
    }
	return(i);
}