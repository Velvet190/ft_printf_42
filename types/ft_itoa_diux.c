/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_diux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:16:37 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/27 14:53:32 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static char	*ft_itoaa_signd(int value, char *str, int base)
{
	long	val;
	long	nb;

	val = value;
	if (val < 0)
	{
		*str = '-';
		str++;
		val = -val;
	}
	if (val >= base)
	{
		str = ft_itoaa_signd(val / base, str, base);
	}
	nb = val % base;
	if (nb > 9)
		*str = (nb - 10) + 'a';
	else
		*str = nb + '0';
	str[1] = '\0';
	return (str + 1);
}

static char	*ft_itoaa_unsignd(unsigned long int value, char *str,
		unsigned int base)
{
	long unsigned	val;
	long unsigned	nb;

	val = value;
	if (val >= base)
	{
		str = ft_itoaa_unsignd(val / base, str, base);
	}
	nb = val % base;
	if (nb > 9)
		*str = (nb - 10) + 'a';
	else
		*str = nb + '0';
	str[1] = '\0';
	return (str + 1);
}

int	ft_itoa_signd(int n, int base)
{
	size_t	len;
	long	val;
	char	*res;
	int		i;

	i = 0;
	val = n;
	len = 0;
	if (val <= 0)
		len++;
	while (val != 0)
	{
		val /= base;
		len++;
	}
	res = malloc(len + 1);
	if (!res)
		return (0);
	ft_itoaa_signd(n, res, base);
	while (res[i])
	{
		write(1, &res[i++], 1);
	}
	free(res);
	return (i);
}

int	ft_itoa_unsignd(unsigned int n, int base)
{
	size_t	len;
	long	val;
	char	*res;
	int		i;

	i = 0;
	val = n;
	len = 0;
	if (val <= 0)
		len++;
	while (val != 0)
	{
		val /= base;
		len++;
	}
	res = malloc(len + 1);
	if (!res)
		return (0);
	ft_itoaa_unsignd(n, res, base);
	while (res[i])
	{
		write(1, &res[i++], 1);
	}
	free(res);
	return (i);
}
