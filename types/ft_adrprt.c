/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adrprt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 13:46:49 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/27 14:38:55 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_adrprt(void *adr)
{
	unsigned long int	len;
	unsigned long int	nadr;

	nadr = (unsigned long int)adr;
	len = 0;
	if (!adr)
		return (len += write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	len += ft_itoa_unsignd(nadr, 16);
	return (len);
}
