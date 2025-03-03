/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:54:02 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:54:02 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*ptr;
	int		i;

	len = ft_strlen(str);
	i = 0;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*
#include <stdio.h>

int main(void)
{
    const char *original = "Hello, world!";
    char *copy = ft_strdup(original);

    if (copy != NULL)
    {
        printf("Original: %s\n", original);
        printf("Copy: %s\n", copy);

        // Freigabe des reservierten Speichers
        free(copy);
    }

    return 0;
}*/
