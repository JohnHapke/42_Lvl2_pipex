/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:43:37 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:43:37 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;
	size_t				i;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

/*
#include <stddef.h>  // Für size_t
int main(void)
{
    const char *str1 = "Hello, world!";
    const char *str2 = "Hello, World!";
    size_t num = 13;

    int result = ft_memcmp(str1, str2, num);

    if (result == 0)
        write(1, "Memory areas are equal\n", 23);
    else if (result < 0)
        write(1, "str1 is less than str2\n", 23);
    else
        write(1, "str1 is greater than str2\n", 26);

    return 0;
} */
