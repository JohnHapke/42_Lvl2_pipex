/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:45:58 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:45:58 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int i, size_t len)
{
	char	*ptr;

	ptr = (char *)str;
	while (len > 0)
	{
		ptr[len -1] = i;
		len--;
	}
	return (str);
}

/*
#include <string.h>
#include <stdio.h>
int main() {
    // Anwendungsfall 1: Initialisierung eines Arrays
    char arr[10];
    ft_memset(arr, 'A', sizeof(arr));
    printf("Anwendungsfall 1: %s\n", arr);

    // Anwendungsfall 2: Nullsetzen eines Integer-Arrays
    int intArr[5];
    ft_memset(intArr, 0, sizeof(intArr));
    printf("Anwendungsfall 2: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", intArr[i]);
    }
    printf("\n");
    return 0;
} */
