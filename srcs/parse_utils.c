#include "cub3D.h"

int  parse_argv(char *str)
{
    int n;

    n = ft_strlen(str);
    str += (n - 4);
    if (ft_strncmp(str, ".cub", 5) == 0)
        return (0);
    return (1);
}

int double_ft_len(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}