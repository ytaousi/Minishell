/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaousi <ytaousi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 23:00:09 by ytaousi           #+#    #+#             */
/*   Updated: 2019/10/20 20:13:09 by ytaousi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_check_set(char const pointer, char const *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (pointer == set[i])
			return (1);
		else
			i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		s1_len;
	int		i;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	i = 0;
	trim = NULL;
	while (s1[i] != '\0' && ft_check_set(s1[i], set))
		i++;
	while (s1_len > 0 && ft_check_set(s1[s1_len - 1], set))
		s1_len--;
	if (i > (s1_len - 1))
		return (ft_strdup(""));
	trim = ft_substr(s1, i, (s1_len - i));
	return (trim);
}
