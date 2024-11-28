/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:31:33 by yael-maa          #+#    #+#             */
/*   Updated: 2024/11/25 05:30:32 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1

#endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
int     ft_strlen(char *str);
char    *ft_strchr(char *str, char c);
char    *ft_strdup(char *str);
char	*buffs_to_line(char	*line, int fd);
char    *buffer_left(char *str);
char    *get_lines(char *line);

#endif