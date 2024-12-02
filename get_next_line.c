/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:33:00 by yael-maa          #+#    #+#             */
/*   Updated: 2024/12/02 17:10:41 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buffer_to_line(char *line, int fd)
{
	char	*buffer;
	int		read_byte;

	if (!line)
		line = ft_strdup("");
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(line), line = NULL, NULL);
	read_byte = 1;
	while (read_byte > 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte < 0)
			return (free(buffer), free(line), buffer = NULL, line = NULL, NULL);
		buffer[read_byte] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (free(buffer), NULL);
		if (ft_strchr(line, '\n'))
			break ;
	}
	if (read_byte == 0 && *line == '\0')
		return (free(line), free(buffer), line = NULL, NULL);
	free(buffer);
	return (line);
}

char	*buffer_left(char *str)
{
	char	*buffer;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	buffer = NULL;
	i = -1;
	while (str[++i] && str[i] != '\n')
		;
	if (str[i] == '\n')
	{
		i++;
		buffer = malloc(ft_strlen(str) - i + 1);
		if (!buffer)
			return (free(str), str = NULL, NULL);
		j = 0;
		while (str[i])
			buffer[j++] = str[i++];
		buffer[j] = '\0';
	}
	free(str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	line = NULL;
	if ((fd < 0 || fd >= OPEN_MAX) || BUFFER_SIZE <= 0)
	{
		if (str)
			free(str);
		return (NULL);
	}
	str = buffer_to_line(str, fd);
	if (!str)
		return (NULL);
	line = get_lines(str);
	if (!line)
		return (NULL);
	str = buffer_left(str);
	return (line);
}
