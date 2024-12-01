#include "get_next_line_bonus.h"

char    *buffer_to_line(char *line, int fd)
{
    char    *buffer;
    int read_byte;

    if (!line)
        line = ft_strdup("");
    buffer = malloc((size_t)BUFFER_SIZE + 1);
    if (!buffer)
        return (free(line), line= NULL, NULL);
    read_byte = 1;
    while (read_byte > 0)
    {
        read_byte = read(fd, buffer, BUFFER_SIZE);
        if (read_byte < 0)
            return (free(buffer), free(line), buffer = NULL, line = NULL, NULL);
        buffer[read_byte] = '\0';
        line = ft_strjoin(line, buffer);
        if (ft_strchr(line, '\n'))
            break;
    }
    if (read_byte == 0 && *line == '\0')
        return (free(line), free(buffer), line = NULL);
    if (buffer)
        free(buffer);
    return (line);
}
char    *get_next_line(int fd)
{
    static char    *str[OPEN_MAX];
    char           *line;

    line = NULL;
    if ((fd < 0 || fd >= OPEN_MAX) || BUFFER_SIZE <= 0)
        return (NULL);
    str[fd] = buffer_to_line(str[fd], fd);
    if (!str[fd])
        return (NULL);
    line = get_lines(str[fd]);
    str[fd] = buffer_left(str[fd]);
    return (line);
}
// // void    ft()
// // {
// //     system("leaks a.out");
// // }
// int main()
// {
//     // atexit(ft);
//     char    *s;
//     int     fd = open("test.txt", O_RDONLY);

//     while (get_next_line(fd))
//     {
//         s = get_next_line(fd);
//         printf("%s", s);
//         free(s);
//         // s = get_next_line(fd);
//     }
//     close(fd);
//     return (0);
// }