/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:31:09 by yael-maa          #+#    #+#             */
/*   Updated: 2024/11/25 06:13:46 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buffs_to_line(char	*line, int fd)
{
	char	*buffer;
	char	*tmp;
	int		read_byte;
	
	if (!line)
		line = ft_strdup("");
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(line);
		return (NULL);
	}
	read_byte = 1;
	while (!ft_strchr(line, '\n') && read_byte > 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		tmp = ft_strjoin(line, buffer);
		if (!tmp)
		{ 
			free(buffer);
			free(line);
			return (NULL);
        }
		line = tmp;
	}
	free(buffer);
	if (read_byte == 0 && *line == '\0')
	{
		free(line);	
		return (NULL);
	}
	return (line);
}
char    *get_next_line(int fd)
{
	static char	*str;
	char		*line;
	
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = buffs_to_line(str, fd);
	if (!str)
		return (NULL);
	line = get_lines(str);
	if (!line)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = buffer_left(str);
	return (line);
}

// int main()
// {
// 	char    *buffer;
// 	int fd = open("text.txt", O_RDWR);
// 	// lseek(fd, 0, SEEK_SET);
// 	buffer = get_next_line(fd);
// 	printf("%s", buffer);
// 	buffer = get_next_line(fd);
// 	printf("%s", buffer);
// 	free(buffer);
// 	close(fd);
// }