/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaousi <ytaousi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 21:00:54 by ytaousi           #+#    #+#             */
/*   Updated: 2019/10/21 15:50:47 by ytaousi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_dealocate(char **splited, int nb_words)
{
	int index;

	index = 0;
	while (index < nb_words)
	{
		free(splited[index]);
		index++;
	}
	free(splited);
	return (NULL);
}

static int		ft_countwords(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
			i++;
		count++;
	}
	return (count);
}

static char		*ft_function(char const *s, int *pos, char c)
{
	char	*word;
	int		previous;
	int		end;

	end = *pos;
	while (s[end] == c)
		end++;
	previous = end;
	while (s[end] != c && s[end] != '\0')
		end++;
	word = ft_substr(s, previous, (end - previous));
	*pos = end;
	return (word);
}

char			**ft_split(char const *s, char c)
{
	char	**splited;
	int		i;
	int		word_index;
	int		nb_words;

	if (!s)
		return (0);
	i = 0;
	word_index = 0;
	nb_words = ft_countwords(s, c);
	splited = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!splited)
		return (NULL);
	while (word_index < nb_words)
	{
		if (!(splited[word_index] = ft_function(s, &i, c)))
			return (ft_dealocate(splited, nb_words));
		word_index++;
	}
	splited[word_index] = NULL;
	return (splited);
}
