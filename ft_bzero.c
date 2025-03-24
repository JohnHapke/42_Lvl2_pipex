/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:34:30 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:34:30 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t len)
{
	char	*ptr;

	ptr = (char *)str;
	while (len > 0)
	{
		ptr[len - 1] = 0;
		len--;
	}
	return (str);
}

/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    // Anwendungsfall 1: Nullsetzen eines Char-Arrays (Puffer)
    char buffer[10] = "Hello";
    printf("Vor ft_bzero: %s\n", buffer);
    ft_bzero(buffer, sizeof(buffer));
    printf("Nach ft_bzero: ");
    for(int i = 0; i < sizeof(buffer); i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    // Anwendungsfall 2: Nullsetzen eines Integer-Arrays
    int intArr[5] = {1, 2, 3, 4, 5};
    printf("Vor ft_bzero: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", intArr[i]);
    }
    printf("\n");
    ft_bzero(intArr, sizeof(intArr));
    printf("Nach ft_bzero: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", intArr[i]);
    }
    printf("\n");

    return 0;
} */
