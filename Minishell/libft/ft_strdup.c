/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaousi <yassir.taous@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:14:01 by ytaousi           #+#    #+#             */
/*   Updated: 2019/10/17 12:08:43 by ytaousi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *sdup;

	sdup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!sdup)
		return (NULL);
	ft_memcpy(sdup, s, (ft_strlen(s) + 1));
	return (sdup);
}
