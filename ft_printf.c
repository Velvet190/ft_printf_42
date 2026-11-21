/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 01:06:41 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/21 02:05:33 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		i;
	int		j;
	i = 0;
	j = 0;
	va_start(args, form);
	while (form[i])
	{
		while (form[i] && form[i] != '%')
		{
			write(1, &form[i], 1);
			i++;
		}
// A faire pour demain uenfonction qui check de quel type on parle et renvoie un int et en fonction de ce INT on fait les differentes choses.
		if ((form[i + 1] != '\0' && form[i + 1] != '%') || form[i + 1] == 'c' || form[i + 1] == 's')
		{
			i++;
			if (form[i] == 'c')
			{
                int chr = va_arg(args, int);
                write(1, &chr, 1);
                i++;
			}
			else if (form[i] == 's')
            {
                char *str = va_arg(args, char *);
                while (str[j])
                {
                    write(1, &str[j], 1);
                    j++;
                }
                j = 0;
                i++;
            }
            
		}
	}
    return(1);
}
int	main(void)
{
    ft_printf("Bonjour %s", "Velvet\n");
}