/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:55:56 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:55:56 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	i = 0;
	if (dest_len >= n)
		return (src_len + n);
	while (src[i] != '\0' && (dest_len + i) < (n - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*
#include <stdio.h>
#include <unistd.h>
// Deklaration der ft_strlcat Funktion
size_t ft_strlcat(char *dest, const char *src, size_t size);

int main() {
    char dest[20] = "Hello";
    const char src[] = ", World!";
    size_t size = sizeof(dest); // Größe des Puffers

    // Ausgabe vor dem Aufruf von ft_strlcat
    printf("Vorher: dest = '%s', src = '%s'\n", dest, src);

    // Aufruf der ft_strlcat Funktion
    size_t result = ft_strlcat(dest, src, size);

    // Ausgabe nach dem Aufruf von ft_strlcat
    printf("Nachher: dest = '%s', src = '%s'\n", dest, src);
    printf("Zurückgegebene Länge: %zu\n", result);

    return 0;
} */
