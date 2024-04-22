#include "cub3D.h"
    // handle spaces between 1
    // check space is surronded by 1 or space, end should no connecting with 0
    // handle walls
    // ◦ The map must be closed/surrounded by walls, if not the program must return
    //Spaces are a valid part of the map and are up to you to handle.
    // check the whohle map was surrended by 1
    // handle player_ppsition
    // the player not surronded by 1
    // should have an exit??

static void new_map_value(char **map, char **map_copy, int i, int maxi)
{
    int j;

    j = 0;
    while (map[i][j])
    {
        map_copy[i][j] = map[i][j];
        j++;
    }
    while (j < maxi)
    {
        map_copy[i][j] = '2';
        j++;
    }
    map_copy[i][j] = '\0';
}

static void new_map(char **map, char **map_copy, int maxi, t_var *var)
{
    int i;
    int len;

    i = 0;
    while (map[i])
    {
        len = ft_strlen(map[i]);
        if (i == maxi)
        {
            map_copy[i] = ft_strdup(map[i]);
            if (!map_copy[i])
                return (free_double_ptr(map_copy), error_malloc(var));
        }
        else
        {
            map_copy[i] = malloc(sizeof(char) * (maxi + 1));
            if (!map_copy[i])
                return (free_double_ptr(map_copy), error_malloc(var));
            new_map_value(map, map_copy, i, maxi);
        }
        i++;
    }
    map_copy[i] = 0;
}

int check_map_numbers(t_var *var, char **map)
{
    int     len;
    int     i;
    char    **map_copy;
    int     maxi;

    i = 0;
    maxi = 0;
    len = double_ft_len(map);
    map_copy = malloc(sizeof(char *) * (len + 1));
    if (!map_copy)
        error_malloc(var);
    while(map[i])
    {
        len = ft_strlen(map[i]);
        if (len > maxi)
            maxi = len;
        i++;
    }
    new_map(map, map_copy, maxi, var);
    if (handle_spaces(map_copy) == 1)
        return (err_return_info("Error map spaces wrong", var), free_double_ptr(map_copy), 1);
    if (handle_walls(var, map) == 1)
        return (free_double_ptr(map_copy), 1);

    // if in the subject the map valid, this condition should remove
    // 0 should be surrronded by 1 or not
    if (handle_inner_zero(map_copy) == 1)
        return (err_return_info("Error 0 not closed wall", var), free_double_ptr(map_copy), 1);
    free_double_ptr(map_copy);
    return (0);
}