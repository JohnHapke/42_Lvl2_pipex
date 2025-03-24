/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:56:54 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:56:54 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < (n - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

/*
#include <stdio.h>
#include <unistd.h>
int main() {
    char src[] = "Hello, World!";
    char dest[20];

    size_t copied = ft_strlcpy(dest, src, sizeof(dest));
    
    printf("Quelle: %s\n", src);
    printf("Ziel: %s\n", dest);
    printf("Länge der Quellzeichenkette: %zu\n", copied);

    return 0;
}*/
