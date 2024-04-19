#include "cub3D.h"

int check_map_numbers(t_var *var, char **map)
{
    int i;


    // handle spaces between 1
    // check space is surronded by 1 or space, end should no connecting with 0
    // handle walls
    // ◦ The map must be closed/surrounded by walls, if not the program must return
    //Spaces are a valid part of the map and are up to you to handle.
    // check the whohle map was surrended by 1
    // handle player_ppsition
    // the player not surronded by 1
    // should have an exit??
    (void)var;
    i = 0;
    while(map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
    return (0);
}