/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaousi <ytaousi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:04:36 by ytaousi           #+#    #+#             */
/*   Updated: 2019/10/23 04:58:44 by ytaousi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (!s && !len && find)
		return (NULL);
	if (find[0] == '\0')
		return ((char *)s);
	while (s[i] != '\0' && i < len)
	{
		j = 0;
		while (find[j] == s[i + j] && i + j < len)
		{
			j++;
			if (find[j] == '\0')
				return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}
