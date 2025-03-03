/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:55:27 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:55:27 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

/*
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    const char *str1 = "Hello, ";
    const char *str2 = "world!";
    
    char *joined_str = ft_strjoin(str1, str2);

    if (joined_str != NULL)
    {
        printf("Joined String: %s\n", joined_str);

        // Freigabe des reservierten Speichers
        free(joined_str);
    }

    return 0;
} */
