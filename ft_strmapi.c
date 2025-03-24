/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:58:16 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:58:16 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	example_function(char c)
{
	return (c + 1);
} */

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t	len_str;
	char	*ptr;
	size_t	i;

	len_str = ft_strlen(str);
	ptr = (char *)malloc((len_str + 1) * sizeof(char));
	i = 0;
	if (!ptr)
		return (NULL);
	while (str[i])
	{
		ptr[i] = (*f)(i, str[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*
#include <stdio.h>
int main(void)
{
    char const *s = "Hello";
    char *result = ft_strmapi(s, example_function);

    if (result)
    {
        printf("Result: %s\n", result);
        free(result);
    }
    return 0;
} */
