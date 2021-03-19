/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaousi <ytaousi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 21:52:23 by ytaousi           #+#    #+#             */
/*   Updated: 2019/10/23 17:17:10 by ytaousi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t len_dst;

	if (!dst && src && !size)
		return (ft_strlen(src));
	len_dst = ft_strlen(dst);
	if (len_dst > size)
		return (size + ft_strlen(src));
	ft_strlcpy(dst + len_dst, src, size - len_dst);
	return (len_dst + ft_strlen(src));
}
