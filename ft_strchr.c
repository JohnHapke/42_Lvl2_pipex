/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:52:55 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:52:55 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int i)
{
	unsigned char	c;

	c = (unsigned char)i;
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}

/*
#include <stddef.h>  // Für NULL
int main(void)
{
    const char str[] = "Hello, World!";
    char c = 'o';
    char *result = ft_strchr(str, c);

    if (result != NULL)
        write(1, result, 1);  // Gibt das gefundene Zeichen aus
    else
        write(1, "Zeichen nicht gefunden\n", 23);

    return 0;
} */
