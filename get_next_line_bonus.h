#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10

#endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>

char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strchr(char *str, int c);
char    *ft_strdup(char *str);
char    *buffer_to_line(char *line, int fd);
char    *get_lines(char *str);
size_t  ft_strlen(char  *str);
char    *buffer_left(char *str);

#endif