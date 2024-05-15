#include "../inc/cub3D.h"

/*
    set player coordinate and camerax y value
    according to the direction of player
*/
void set_player_direction(t_var *var)
{
    if (var->player.player_dir == 'N')
    {
        var->player.direction_x = 0.0f;
        var->player.direction_y = 1.0f;
    }
    else if (var->player.player_dir == 'S')
    {
        var->player.direction_x = 0.0f;
        var->player.direction_y = -1.0f;
    }
    else if (var->player.player_dir == 'E')
    {
        var->player.direction_x = 1.0f;
        var->player.direction_y = 0.0f;
    }
    else if (var->player.player_dir == 'W')
    {
        var->player.direction_x = -1.0f;
        var->player.direction_y = 0.0f;
    }
}

void set_camera_value(t_var *var)
{
    if (var->player.player_dir == 'N')
    {
        var->camerax = 0.66;
        var->cameray = 0;
    }
    else if (var->player.player_dir == 'S')
    {
        var->camerax = -0.66;
        var->cameray = 0;
    }
    else if (var->player.player_dir == 'E')
    {
        var->camerax = 0;
        var->cameray = -0.66;
    }
    else if (var->player.player_dir == 'W')
    {
        var->camerax = 0;
        var->cameray = 0.66;
    }
}
