#include "../inc/cub3D.h"
/*
So when moving back and forth

Pos add dir(*weight) to (move forward)
Pos Subtract dir(* weight) from (move backwards)
Weights are used when you want to control the speed of a player’s movement.

posX += dirX * WEIGHT;

posY += dirY * WEIGHT;
*/

# define PLAYER_MOVE 0.1

void player_up_move(t_var *var)
{
    int new_posx;
    int new_posy;

    new_posx = var->player.position_x + var->player.direction_x * PLAYER_MOVE;
    new_posy = var->player.position_y - var->player.direction_y * PLAYER_MOVE;
    if (var->map[(int)var->player.position_y][(int)new_posx] != '1')
        var->player.position_x -= var->player.direction_x * PLAYER_MOVE;
    if (var->map[(int)new_posy][(int)var->player.position_x] != '1')
        var->player.position_y += var->player.direction_y * PLAYER_MOVE;

            printf("%d %d\n",(int) var->player.position_x, (int) var->player.position_y);

    if (var->map[(int)var->player.position_y][(int)new_posx] || var->map[(int)new_posy][(int)var->player.position_x])
        hit_value_set(var);

}
// void move_player(t_var *var)
// {
//     if (var->move.up_move == 1)
//         player_up_move(var);
// }
// void player_left_move(t_var *var)
// {
//     int new_posx;
//     int new_posy;

//     new_posy = var->player.position_y - var->player.direction_x * DISTANCE;    
//     new_posx = var->player.position_x - var->player.direction_y * DISTANCE;
//     if (!collion(var->map, (int)var->player.position_y, (int)new_posx))
//         var->player.position_x -= var->player.direction_y * SPEED;
//     if (!collion(var->map, (int)new_posy, (int)var->player.position_x))
//         var->player.position_x -= var->player.direction_x * SPEED;
// }

// void player_right_move(t_var *var)
// {
//     int new_posx;
//     int new_posy;

    
// }

// void player_up_move(t_var *var)
// {
//     int new_posx;
//     int new_posy;

//     new_posy = var->player.position_y - var->player.direction_y * DISTANCE;    
//     new_posx = var->player.position_x + var->player.direction_x * DISTANCE;
//     if (!collion(var->map, (int)var->player.position_y, (int)new_posx))
//         var->player.position_x += var->player.direction_x * SPEED;
//     if (!collion(var->map, (int)new_posy, (int)var->player.position_x))
//         var->player.position_y += var->player.direction_y * SPEED;
// }

// void player_down_move(t_var *var)
// {
//     int new_posx;
//     int new_posy;

//     new_posy = var->player.position_y + var->player.direction_y * DISTANCE;    
//     new_posx = var->player.position_x - var->player.direction_x * DISTANCE;
//     if (!collion(var->map, (int)var->player.position_y, (int)new_posx))
//         var->player.position_x -= var->player.direction_x * SPEED;
//     if (!collion(var->map, (int)new_posy, (int)var->player.position_x))
//         var->player.position_y -= var->player.direction_y * SPEED;
// }