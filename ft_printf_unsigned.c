/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:40:14 by jhapke            #+#    #+#             */
/*   Updated: 2025/02/19 08:40:09 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digit_uns(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa_uns(unsigned int dec)
{
	char	*result;
	int		len;

	len = ft_count_digit_uns(dec);
	result = (char *)malloc((len + 1) * sizeof(char));
	result[len] = '\0';
	if (dec == 0)
		result[0] = '0';
	while (len > 0)
	{
		result[--len] = (dec % 10) + '0';
		dec /= 10;
	}
	return (result);
}

int	ft_printf_u(unsigned int n)
{
	char	*str;
	int		count;

	str = ft_itoa_uns(n);
	count = ft_strlen(str);
	if (!str)
		return (0);
	write(1, str, count);
	free (str);
	return (count);
}
