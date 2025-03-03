/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:41:01 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:41:01 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
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
	len_n = ft_count_digits(n);
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

/*
#include <stdio.h>  // Zum Testen
int main(void)
{
    printf("itoa(0) = %s\n", ft_itoa(0));
    printf("itoa(-123) = %s\n", ft_itoa(-123));
    printf("itoa(4567) = %s\n", ft_itoa(4567));
    return 0;
} */
