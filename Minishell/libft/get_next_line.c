/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaousi <ytaousi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:39:24 by ytaousi           #+#    #+#             */
/*   Updated: 2019/10/29 13:45:52 by ytaousi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_returnfreebuff(int nb_bytes, char** buffer)
{
	if ((!nb_bytes && *buffer[0] == '\n'))
	{
		free(*buffer);
		*buffer = NULL;
		return (1);
	}
	free(*buffer);
	*buffer = NULL;
	return (0);
}

static	int		ft_readtheline(char* buffer, char** line, char** rest, int fd)
{
	char* tmp;
	char* pointer;
	int		nb_bytes;

	while ((nb_bytes = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[nb_bytes] = '\0';
		if ((pointer = ft_strchr(buffer, '\n')) != NULL)
		{
			*pointer = '\0';
			tmp = *line;
			*line = ft_strjoin(*line, buffer);
			free(tmp);
			tmp = *rest;
			*rest = ft_strdup(pointer + 1);
			free(tmp);
			free(buffer);
			return (1);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buffer);
		free(tmp);
	}
	return (ft_returnfreebuff(nb_bytes, &buffer));
}

static	int		ft_checktherest(char** rest, char** line, char* buffer)
{
	char* tmp;
	char* pointer;

	if (!*rest)
		return (0);
	if ((pointer = ft_strchr(*rest, '\n')) != NULL)
	{
		*pointer = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, *rest);
		free(tmp);
		tmp = *rest;
		*rest = ft_strdup(pointer + 1);
		free(tmp);
		free(buffer);
		return (1);
	}
	tmp = *line;
	*line = ft_strjoin(*line, *rest);
	free(tmp);
	tmp = NULL;
	free(*rest);
	*rest = NULL;
	return (0);
}

int				get_next_line(int fd, char** line)
{
	static	char* rest;
	char* buffer;

	if (fd < 0 || read(fd, NULL, 0) != 0 || line == NULL || BUFFER_SIZE < 0)
		return (-1);
	if (!(buffer = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	*line = ft_strdup("");
	if (ft_checktherest(&rest, line, buffer))
		return (1);
	return (ft_readtheline(buffer, line, &rest, fd));
}
