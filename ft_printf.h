/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:36:45 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/23 16:40:22 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_ARG_H
# define PRINT_ARG_H

#include <stdarg.h>
#include <unistd.h>

int		print_arg(char c, va_list args);
char	*ft_itoa(int n);
int		check_conv(const char *form, int i, va_list args);

#endif