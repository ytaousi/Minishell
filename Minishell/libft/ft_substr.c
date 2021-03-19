/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaousi <ytaousi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:37:18 by ytaousi           #+#    #+#             */
/*   Updated: 2019/10/20 19:07:53 by ytaousi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_check_len(size_t a, size_t b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	size;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	size = ft_check_len(len, ft_strlen(s + start));
	sub = (char *)malloc(sizeof(char) * size + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, size);
	sub[size] = '\0';
	return (sub);
}
