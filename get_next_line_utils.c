/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:33:24 by yael-maa          #+#    #+#             */
/*   Updated: 2024/11/25 05:33:40 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;
    
    if (!str)
        return (0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}
char    *ft_strdup(char *str)
{
    char    *s;
    int     i;
    
    if (!str)
        return (NULL);
    s = malloc(sizeof(char) * ft_strlen(str) + 1);
    if (!s)
        return (NULL);
    i = 0;
    while (str[i])
    {
        s[i] = str[i];
        i++;
    }
    s[i] = '\0';
    return (s);
}
char    *ft_strchr(char *str, char c)
{
    int i;

    if (!str)
        return (NULL);
    if (c == '\0')
        return ((char *)&str[ft_strlen(str)]);
    i = 0;
    while (str[i])
    {
        if (str[i] == (char)c)
            return ((char *)&str[i]);
        i++;
    }
    return (NULL);
}
char    *get_lines(char *line)
{
    char    *str;
    int     i;

    i = 0;
    while (line[i] && line[i] != '\n')
        i++;
    str = malloc(sizeof(char) * (i + 2));
    if (!str)
        return (NULL);
    i = 0;
    while (line[i] && line[i] != '\n')
    {
        str[i] = line[i];
        i++;
    }
    if (line[i] == '\n')
    {
        str[i] = line[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
char    *ft_strjoin(char *s1, char *s2)
{
    char    *s3;
    int     size;
    int     i;
    int     j;
    
    if (!s1)
    {
        s1 = malloc(sizeof(char) * 1);
        if (!s1)
            return (NULL);
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (NULL);
    size = ft_strlen(s1) + ft_strlen(s2) + 1;
    s3 = malloc(sizeof(char) * size);
    if (!s3)
    {
        free(s1); 
        return (NULL);
    }
    i = 0;
    while (s1[i])
    {
        s3[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        s3[i + j] = s2[j];
        j++;
    }
    s3[j + i] = '\0';
    free(s1);
    return (s3);
}
char    *buffer_left(char *str)
{
    char    *buffer;
    int     size;
    int     i;
    int     j;
    
    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (!str)
        return (NULL);
    if (!str || i >= ft_strlen(str) - 1)
    {
        free(str);
        return (NULL);
    }
    size = ft_strlen(str) - i;
    buffer = malloc(sizeof(char) * size);
    if (!buffer)
    {
        free(str);
        return (NULL);
    }
    i++;
    j = 0;
    while (str[i])
    {
        buffer[j] = str[i];
        j++;
        i++;
    }
    buffer[j] = '\0';
    free(str);
    return (buffer);
}