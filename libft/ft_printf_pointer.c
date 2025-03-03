/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:28:29 by jhapke            #+#    #+#             */
/*   Updated: 2025/01/04 17:28:29 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
		write(1, &buffer[i++], 1);
	return (i);
}

void	ft_sprintf_write(char *buffer, int i)
{
	int	j;

	j = (i - 1);
	while (j >= 0)
	{
		write(1, &buffer[j], 1);
		j--;
	}
}

int	ft_sprintf(unsigned long adress)
{
	char			buffer[20];
	int				i;
	int				digit;

	i = 0;
	digit = 0;
	while (adress > 0)
	{
		digit = adress % 16;
		if (digit < 10)
			buffer[i++] = '0' + digit;
		else
			buffer[i++] = 'a' + (digit - 10);
		adress /= 16;
	}
	buffer[i] = '\0';
	write(1, "0x", 2);
	ft_sprintf_write(buffer, i);
	return (i + 2);
}

int	ft_printf_p(void *ptr)
{
	int				count;
	unsigned long	adress;

	adress = (unsigned long )ptr;
	if (adress == 0)
		count = ft_putstr("(nil)");
	else
		count = ft_sprintf(adress);
	return (count);
}
