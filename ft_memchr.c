/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:42:44 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:42:44 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}

/*
int main(void)
{
    const char *str = "Hello, world!";
    char c = 'w';
    size_t n = 13;

    char *result = (char *)ft_memchr(str, c, n);

    if (result != NULL)
        write(1, result, 1);  // Gibt das gefundene Zeichen aus
    else
        write(1, "Zeichen nicht gefunden\n", 23);

    return 0;
}*/
