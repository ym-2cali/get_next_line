#include "get_next_line_bonus.h"

size_t  ft_strlen(char  *str)
{
    size_t  i;

    if (!str)
        return (0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strdup(char *str)
{
    char    *buffer;
    size_t  i;
    size_t  size;

    size = ft_strlen(str) + 1;
    buffer = malloc(size);
    if (!buffer)
        return (NULL);
    i = -1;
    while (str[++i])
        buffer[i] = str[i];
    buffer[i] = '\0';
    return (buffer);
}
char    *ft_strchr(char *str, int c)
{
    int i;

    if (!str)
        return (NULL);
    i = 0;
    while (str[i])
    {
        if (str[i] == (char)c)
            return ((char *)str);
        i++;
    }
    if (str[i] == (char)c)
        return ((char *)str);
    return (NULL);
}
char    *ft_strjoin(char *s1, char *s2)
{
    char    *s3;
    size_t  size;
    size_t  i;
    size_t  j;

    if (!s1)
        return (NULL);
    if (!s1 && !s2)
        return (NULL);
    if (s1 && !s2)
        return (free(s1), s1 = NULL, NULL);
    size = ft_strlen(s1) + ft_strlen(s2) + 1;
    s3 = malloc(size);
    if (!s3)
        return (free(s1), free(s2), s1 = NULL, s2 = NULL, NULL);
    i = -1;
    while (s1[++i])
        s3[i] = s1[i];
    j = -1;
    while (s2[++j])
        s3[j + i] = s2[j];
    s3[j + i] = '\0';
    free(s1);
    return (s3);
}
char    *get_lines(char *str)
{
    char    *line;
    size_t  i;

    if (!str)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        line = malloc(i + 2);
    else
        line = malloc(i + 1);
    if (!line)
        return (free(str), str = NULL, NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        line[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        line[i] = str[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}
char    *buffer_left(char *str)
{
    char    *buffer;
    size_t  i;
    size_t  j;

    if (!str)
        return (NULL);
    buffer = NULL;
    i = 0; 
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i] == '\n')
    {
        i++;
        j = i;
        while (str[j++]);
        buffer = malloc(j - i + 1);
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