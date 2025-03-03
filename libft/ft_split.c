/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:50:31 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:50:31 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(char *str, char c)
{
	int	in_word;
	int	count;

	in_word = 0;
	count = 0;
	while (*str)
	{
		if ((*str != c) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

int	ft_word_len(char *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[i] && str[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

void	ft_free_memory(char **ptr, int index)
{
	while (index--)
		free(ptr[index]);
	free(ptr);
}

char	**ft_split(char *str, char c)
{
	int		index;
	int		j;
	char	**ptr;
	int		a;

	index = 0;
	ptr = (char **)malloc((ft_word_count(str, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	j = 0;
	while (index < ft_word_count(str, c))
	{
		while (str[j] && str[j] == c)
			j++;
		ptr[index] = malloc((ft_word_len(str, c, j) + 1) * sizeof(char));
		if (!ptr[index])
			return (ft_free_memory(ptr, index), NULL);
		a = 0;
		while (str[j] && str[j] != c)
			ptr[index][a++] = str[j++];
		ptr[index][a] = '\0';
		index++;
	}
	ptr[index] = NULL;
	return (ptr);
}
/*
#include <stdio.h>
int main(void)
{
    char str[] = "Hello,world,welcome,to,C,programming";
    char **result = ft_split(str, ',');

    if (result != NULL)
    {
        for (int i = 0; result[i] != NULL; i++)
        {
            printf("%s\n", result[i]);
            free(result[i]);
        }
        free(result);
    }

    return 0;
} */
