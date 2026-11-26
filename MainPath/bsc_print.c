/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsc_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 18:13:06 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/26 18:50:42 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <unistd.h>

int	bsc_print(const char *form, args)
{
	int i = 0;
	int len = 0;
	while (form[i])
    {
        if (form[i + 1] && form[i] == '%')
        {
            i++;
            len += arg_print(form[i], args);
        }
        else
        {
            write(1, &form[i], 1);
            i++;
        }
    }
    return(len + i);
}