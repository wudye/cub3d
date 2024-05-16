#include "../inc/cub3D.h"
/*
So when moving back and forth

Pos add dir(*weight) to (move forward)
Pos Subtract dir(* weight) from (move backwards)
Weights are used when you want to control the speed of a player’s movement.

posX += dirX * WEIGHT;

posY += dirY * WEIGHT;
*/


static bool collion(char **map, int y, int x)
{
    if (map[y][x] == '1')
        return true;
    return false;
}
 
void player_left_move(t_var *var)
{
    int new_posx;
    int new_posy;

    new_posy = var->player.position_y - var->player.direction_x * DISTANCE;    
    new_posx = var->player.position_x - var->player.direction_y * DISTANCE;
    if (!collion(var->map, (int)var->player.position_y, (int)new_posx))
        var->player.position_x -= var->player.direction_y * SPEED;
    if (!collion(var->map, (int)new_posy, (int)var->player.position_x))
        var->player.position_x -= var->player.direction_x * SPEED;
}

void player_right_move(t_var *var)
{
    int new_posx;
    int new_posy;

    new_posy = var->player.position_y + var->player.direction_x * DISTANCE;    
    new_posx = var->player.position_x + var->player.direction_y * DISTANCE;
    if (!collion(var->map, (int)var->player.position_y, (int)new_posx))
        var->player.position_x += var->player.direction_y * SPEED;
    if (!collion(var->map, (int)new_posy, (int)var->player.position_x))
        var->player.position_x += var->player.direction_x * SPEED;
}

void player_up_move(t_var *var)
{
    int new_posx;
    int new_posy;

    new_posy = var->player.position_y - var->player.direction_y * DISTANCE;    
    new_posx = var->player.position_x + var->player.direction_x * DISTANCE;
    if (!collion(var->map, (int)var->player.position_y, (int)new_posx))
        var->player.position_x -= var->player.direction_x * SPEED;
    if (!collion(var->map, (int)new_posy, (int)var->player.position_x))
        var->player.position_x += var->player.direction_x * SPEED;
}

void player_down_move(t_var *var)
{
    int new_posx;
    int new_posy;

    new_posy = var->player.position_y + var->player.direction_y * DISTANCE;    
    new_posx = var->player.position_x - var->player.direction_x * DISTANCE;
    if (!collion(var->map, (int)var->player.position_y, (int)new_posx))
        var->player.position_x -= var->player.direction_x * SPEED;
    if (!collion(var->map, (int)new_posy, (int)var->player.position_x))
        var->player.position_x += var->player.direction_x * SPEED;
}