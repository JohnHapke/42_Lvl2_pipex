/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:40:25 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:40:25 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int i)
{
	if (i >= 32 && i <= 126)
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
    printf("\nResult printable character is passed: %d", ft_isprint(c));

    c = 31; // Nicht druckbares Zeichen
    printf("\nResult non-printable character is passed: %d", ft_isprint(c));

    return 0;
} */