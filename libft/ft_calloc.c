/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:35:18 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:35:18 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, (count * size));
	return (ptr);
}

/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(void)
{
    size_t num_elements = 5;
    size_t size_of_element = sizeof(int);
    
    int *arr = (int *)ft_calloc(num_elements, size_of_element);
    
    if (arr != NULL)
    {
        for (size_t i = 0; i < num_elements; i++)
        {
            printf("%d ", arr[i]);  // Erwartete Ausgabe: 0 0 0 0 0
        }
        
        // Freigabe des reservierten Speichers
        free(arr);
    }
    
    return 0;
} */
