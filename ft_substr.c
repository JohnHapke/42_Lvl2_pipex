/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:03:22 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 15:03:22 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
	{
		ptr = (char *)malloc(1);
		if (ptr)
			ptr[0] = '\0';
		return (ptr);
	}
	if (len > (ft_strlen(str) - start))
		len = ft_strlen(str) - start;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[start + i] && i < len)
	{
		ptr[i] = str[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*
#include <stdlib.h>  // Für malloc und free
int main(void)
{
    const char *original = "Hello, world!";
    unsigned int start = 7;
    size_t length = 5;

    char *substring = ft_substr(original, start, length);

    if (substring != NULL)
    {
        printf("Original: %s\n", original);
        printf("Substring: %s\n", substring);

        // Freigabe des reservierten Speichers
        free(substring);
    }
    return 0;
} */
