/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:01:05 by jhapke            #+#    #+#             */
/*   Updated: 2024/12/26 15:01:05 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstr, const char *nstr, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	nstr_len;

	nstr_len = ft_strlen(nstr);
	i = 0;
	if (nstr_len == 0 || hstr == nstr)
		return ((char *)hstr);
	while (i < n && hstr[i] != '\0')
	{
		if (hstr[i] == nstr[0])
		{
			j = 0;
			while ((i + j) < n
				&& hstr[i + j] == nstr[j] && hstr[i + j] != '\0')
			{
				if (nstr[j + 1] == '\0')
					return ((char *)(hstr + i));
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

/*
int main(void)
{
    const char *haystack = "Hello, world!";
    const char *needle = "world";
    size_t num = 13;

    const char *result = ft_strnstr(haystack, needle, num);

    if (result != NULL)
        write(1, result, 5);  // Gibt "world" aus
    else
        write(1, "Substring nicht gefunden\n", 25);

    return 0;
} */
