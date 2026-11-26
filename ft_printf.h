/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:36:45 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/26 19:11:43 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_ARG_H
# define PRINT_ARG_H

#include <stdarg.h>
#include <unistd.h>

int	ft_putstr(char *s);
int	ft_putchar(char c);
char	*ft_itoa(int n);
int	ft_printf(const char *form, ...);
int chk_prc(char *str);
int check_conv(char c);
int	bsc_print(const char *form, args);
int arg_print(char c, va_list args);

#endif