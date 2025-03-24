/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:56:50 by jhapke            #+#    #+#             */
/*   Updated: 2025/02/19 08:40:07 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_aux(const char *format, va_list args)
{
	int		count;

	count = 0;
	if (*(format) == 'c')
		count = (ft_printf_c(va_arg(args, int)));
	else if ((*(format) == 'd' || *(format) == 'i'))
		count = (ft_printf_dec(va_arg(args, int)));
	else if (*(format) == 'p')
		count = (ft_printf_p(va_arg(args, void *)));
	else if (*(format) == 's')
		count = (ft_printf_s(va_arg(args, const char *)));
	else if (*(format) == 'u')
		count = (ft_printf_u(va_arg(args, unsigned int)));
	else if (*(format) == '%')
		count = (ft_printf_c('%'));
	else if (*(format) == 'x')
		count = (ft_printf_x(va_arg(args, unsigned int)));
	else if (*(format) == 'X')
		count = (ft_printf_xup(va_arg(args, unsigned int)));
	else
		count--;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_printf_aux(format, args);
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
