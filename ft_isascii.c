/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:39:02 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:39:02 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int i)
{
	if (i >= 0 && i <= 127)
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	int c;
    c = 65; // ASCII für 'A'
    printf("\nResult when ASCII character is passed: %d", ft_isascii(c));

    c = 200; // Nicht-ASCII-Zeichen
    printf("\nResult when non-ASCII character is passed: %d", ft_isascii(c));

    return 0;
} */