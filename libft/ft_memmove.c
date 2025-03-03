/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:45:07 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:45:07 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src)
		return (dest);
	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>  // Zum Vergleich mit Standard `memmove`

int main() {
    // Fall 1: Kopieren von vorne nach hinten
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";

    // Standard memmove zum Vergleich
    memmove(str1 + 7, str1, 5);
    printf("Standard memmove (vorne nach hinten): %s\n", str1);

    // Benutzerdefinierte ft_memmove
    ft_memmove(str2 + 7, str2, 5);
    printf("Benutzerdefinierte ft_memmove (vorne nach hinten): %s\n", str2);

    // Fall 2: Kopieren von hinten nach vorne
    char str3[] = "Hello, World!";
    char str4[] = "Hello, World!";

    // Standard memmove zum Vergleich
    memmove(str3, str3 + 7, 5);
    printf("Standard memmove (hinten nach vorne): %s\n", str3);

    // Benutzerdefinierte ft_memmove
    ft_memmove(str4, str4 + 7, 5);
    printf("Benutzerdefinierte ft_memmove (hinten nach vorne): %s\n", str4);

    return 0;
} */
