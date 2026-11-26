/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:33:50 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/26 18:50:45 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"

int check_conv(char c)
{
    char c;
    char *types = "cspdiuxX%"
    c = form[i + 1];
    while (types[i])
    {
        if(types[i] == c)
            return(1)
        i++;
    }
    return (0);
}