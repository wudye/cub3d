#include "../inc/cub3D.h"


int longest_colum(char **map)
{
    int curr_len;
    int max_len;
    int i;

    i = 0;
    max_len = ft_strlen(map[i]);
    while (map[i])
    {
        curr_len = ft_strlen(map[i]);
        if (max_len < curr_len)
            max_len = curr_len;
        i++;
    }
    return (max_len);
}