/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexadecimal_low.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:50:46 by jhapke            #+#    #+#             */
/*   Updated: 2025/02/19 08:40:30 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_x(unsigned long c)
{
	char	*str;
	int		count;

	str = ft_itoa_hex_l(c);
	if (!str)
		return (0);
	count = ft_strlen(str);
	write(1, str, count);
	free (str);
	return (count);
}

int	ft_count_hex_digits(unsigned long hex)
{
	int	count;

	count = 0;
	if (hex == 0)
		return (1);
	while (hex > 0)
	{
		hex /= 16;
		count++;
	}
	return (count);
}

char	*ft_itoa_hex_l(unsigned long hex)
{
	char	*hex_str;
	int		len;
	char	*str;

	hex_str = "0123456789abcdef";
	len = ft_count_hex_digits(hex);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (hex == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (len > 0)
	{
		str[--len] = hex_str[hex % 16];
		hex /= 16;
	}
	return (str);
}
