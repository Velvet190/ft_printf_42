/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:33:50 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/27 14:32:43 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_conv(char c)
{
	int		i;
	char	*typs;

	i = 0;
	typs = "cspdiuxX%";
	while (typs[i])
	{
		if (typs[i] == c)
			return (1);
		i++;
	}
	return (0);
}
