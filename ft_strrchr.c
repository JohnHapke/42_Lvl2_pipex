/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:01:54 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 15:01:54 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		else
			i--;
	}
	return (0);
}

/*
int	main(void)
{
	char car = 'o';
	const char string[] = "Hello World!";
	char *result = ft_strrchr(string, car);
	
	if (result != 0)
		write(1, result, 1);
	else
		write (1, "kein Wert gefunden", 20);
	return (0);
} */
