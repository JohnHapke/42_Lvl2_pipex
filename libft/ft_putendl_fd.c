/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:46:51 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 14:46:51 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	int	i;

	if (!str)
		return ;
	i = ft_strlen(str);
	write(fd, str, i);
	write(fd, "\n", 1);
}

/*
int main(void)
{
	ft_putendl_fd("Hallo", 1);
	return (0);
} */
