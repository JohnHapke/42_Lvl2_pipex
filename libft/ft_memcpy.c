/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:44:27 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:44:27 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
int main() {
    // Anwendungsfall 1: Kopieren einer Zeichenkette
    char src1[] = "Hello, World!";
    char dest1[20];

    ft_memcpy(dest1, src1, sizeof(src1));
    printf("Anwendungsfall 1: %s\n", dest1);

    // Anwendungsfall 2: Kopieren eines Integer-Arrays
    int src2[] = {1, 2, 3, 4, 5};
    int dest2[5];

    ft_memcpy(dest2, src2, sizeof(src2));
    printf("Anwendungsfall 2: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", dest2[i]);
    }
    printf("\n");

    return 0;
} */
