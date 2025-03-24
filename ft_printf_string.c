/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:01:52 by jhapke            #+#    #+#             */
/*   Updated: 2025/02/19 08:40:12 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_s(const char *ptr)
{
	int		count;

	if (!ptr)
		ptr = "(null)";
	count = ft_strlen(ptr);
	write(1, ptr, count);
	return (count);
}
