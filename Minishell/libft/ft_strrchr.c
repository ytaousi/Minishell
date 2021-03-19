/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaousi <ytaousi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:12:26 by ytaousi           #+#    #+#             */
/*   Updated: 2019/10/22 22:40:49 by ytaousi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s1, int c)
{
	int len;

	len = ft_strlen(s1);
	while (len >= 0)
	{
		if (s1[len] == c)
			return ((char *)s1 + len);
		len--;
	}
	return (0);
}
