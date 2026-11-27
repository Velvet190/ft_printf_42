/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:36:45 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/27 15:29:12 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_itoa(int n, int base);
int	ft_itoa_unsignd(unsigned long int n, int base);
int	ft_itoa_unsigndmajx(unsigned long int n, int base);
int	ft_itoa_signd(int n, int base);
int	ft_adrprt(void *adr);
int	ft_printf(const char *form, ...);
int	chk_prc(char *str);
int	check_conv(char c);
int	bsc_print(const char *form, va_list args);
int	arg_print(char c, va_list args);

#endif