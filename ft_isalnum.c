/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:35:55 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:35:55 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int i)
{
	if ((i >= 'a' && i <= 'z')
		|| (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9'))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
	int	main(void)
	{
			char c;
    c = 'Q';
    printf("\nResult when uppercase alphabet is passed: %d", ft_isalnum(c));

    c = '7';
    printf("\nResult number is passed: %d", ft_isalnum(c));

    c = '+';
    printf("\nResult non-alphanumeric character is passed: %d", ft_isalnum(c));

    return 0;
	} */
