/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:39:28 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:39:28 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	char c;
    c = 'Q';
    printf("\nResult uppercase alphabet is passed: %d", ft_isdigit(c));

    c = '7';
    printf("\nResult number is passed: %d", ft_isdigit(c));

    c='+';
    printf("\nResult non-alphabetic character is passed: %d", ft_isdigit(c));

    return 0;
} */