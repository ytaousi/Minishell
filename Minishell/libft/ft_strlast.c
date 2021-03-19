/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaousi <ytaousi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:39:24 by ytaousi           #+#    #+#             */
/*   Updated: 2020/12/15 13:45:52 by ytaousi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlast(char const* str, char const* last)
{
	int len;
	int l_len;

	len = ft_strlen(str);
	l_len = ft_strlen(last);

	if (l_len > len)
		return (0);
	return(!ft_strncmp(str + len - l_len, last, l_len));
}