#include "../inc/cub3d.h"

bool    check_map_value(t_var *var, char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ' && map[i][j] != '\t' && ft_strchr(PLAYER, map[i][j]) == NULL)
            {
                err_return_info("Error map has novalid char", var);
                return (false);
            }
            j++;
        }
        i++;
    }
    return (true);
}