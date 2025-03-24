/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:02:21 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 15:02:21 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *str, const char *set)
{
	int		start;
	int		end;
	int		i;
	char	*ptr;

	start = 0;
	end = ft_strlen(str);
	while (str[start] && ft_is_in_set(str[start], set))
	{
		start++;
	}
	while (end > start && ft_is_in_set(str[end - 1], set))
	{
		end--;
	}
	ptr = (char *)malloc((end - start + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (start < end)
		ptr[i++] = str[start++];
	ptr[i] = '\0';
	return (ptr);
}

/*
#include <stdio.h>

int main(void)
{
    const char *original = "   Hello, world!   ";
    const char *set = " ";
    
    char *trimmed_str = ft_strtrim(original, set);

    if (trimmed_str != NULL)
    {
        printf("Original: '%s'\n", original);
        printf("Trimmed: '%s'\n", trimmed_str);

        // Freigabe des reservierten Speichers
        free(trimmed_str);
    }

    return 0;
} */
