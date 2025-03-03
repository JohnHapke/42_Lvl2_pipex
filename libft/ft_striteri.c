/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:54:43 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:54:43 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	example_function(char *c)
{
	*c = *c + 1;
}

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!str || !f)
		return ;
	while (str[i] != '\0')
	{
		(*f)(i, &str[i]);
		i++;
	}
	str[i] = '\0';
}

/*
#include <stdio.h>
int main(void)
{
    char s[] = "Hello";
    ft_striteri(s, example_function);

    printf("Result: %s\n", s);
    return 0;
} */
