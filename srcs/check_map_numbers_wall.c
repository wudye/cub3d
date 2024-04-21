#include "cub3D.h"

static int  handle_mid_lines(char **map)
{
    int i;
    int e;
    int len;

    e = double_ft_len(map) - 1;
    i = 1;
    while (i < e)
    {
        len = ft_strlen(map[i]) - 1;
        if (map[i][0] != '1' || map[i][len] != '1')
            return (1);
        i++;
    }
    return (0);
}
static int  handle_first_end_line(char **map)
{
    int e;
    int j;

    j = 0;
    e = double_ft_len(map) - 1;
    while (map[0][j])
    {
        if (map[0][j] != '1' && map[0][j] != ' ')
            return (1);
        j++;
    }
    j = 0;
    while (map[e][j])
    {
        if (map[e][j] != '1' && map[e][j] != ' ')
            return (1);
        j++;
    }
    return (0);
}

static int set_player_value(char **map, t_var *var)
{
    int num;
    int i;
    int j;

    i = 0;
    num = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (ft_strchr(player, map[i][j]))
            {
                var->player_x = i;
                var->player_y = j;
                num += 1;
            }
            j++;
        }
        i++;
    }
    if (num != 1)
        return (1);
    return (0);
}
int handle_walls(t_var *var, char **map)
{
    if (handle_first_end_line(map) == 1)
        return (ft_putstr_fd("Error map walls wrong\n", 2), 1);
    if (handle_mid_lines(map) == 1)
        return (ft_putstr_fd("Error map walls wrong\n", 2), 1);
    if (set_player_value(map, var) == 1)
        return (ft_putstr_fd("Erorr player fail\n", 2), 1);
    return (0);   
}