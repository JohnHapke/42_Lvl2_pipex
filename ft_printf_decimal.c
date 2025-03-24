/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:27:17 by jhapke            #+#    #+#             */
/*   Updated: 2025/01/04 17:27:17 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*ptr;
	int		i;

	len = ft_strlen(str);
	i = 0;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_count_digit(int dec)
{
	int	count;

	count = 0;
	if (dec == 0)
		return (1);
	if (dec < 0)
	{
		dec = -dec;
		count++;
	}
	while (dec > 0)
	{
		dec /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	unsigned int	len_n;
	char			*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len_n = ft_count_digit(n);
	str = (char *)malloc((len_n + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len_n] = '\0';
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[--len_n] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	ft_printf_dec(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	write(1, str, len);
	free (str);
	return (len);
}
