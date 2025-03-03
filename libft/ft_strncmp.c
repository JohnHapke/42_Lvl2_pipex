/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:00:38 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 15:00:38 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
	{
		if (s1[i] != '\0')
			return (s1[i]);
		if (s2[i] != '\0')
			return (-(s2[i]));
	}
	return (0);
}

/*
#include <unistd.h>
#include <stddef.h>  // Für size_t

int main(void)
{
    const char *str1 = "Hello";
    const char *str2 = "Helium";
    size_t n = 3;

    int result = ft_strncmp(str1, str2, n);
	printf("Result: '%d'/n", result);
    return 0;
} */
