#include "../inc/cub3D.h"

/* vector rotate
    To rotate the player’s view left and right, t
    he line of sight ( dirvector: dirX, dirY) and the camera plane
     ( planevector: planeX, planeY) must be rotated together.
    To rotate a vector, multiply it with the rotation matrix
    [ cos(a) -sin(a) ]
    [ sin(a) cos(a) ]
    dirX = dirX * cos(theta) — dirY * sin(theta);
    dirY = dirX * sin(theta) + dirY * cos(theta);
    planeX = planeX * cos(theta) — planeY * sin(theta);
    planeY = planeX * sin(theta) + planeY * cos(theta);
*/

void player_rotate(t_var *var, int change)
{
    double change_angle;
    
    change_angle = (M_PI / 90) * change;
    var->player.direction_x = var->player.direction_x * cos(change_angle) 
    - var->player.direction_y * sin(change_angle);
    var->player.direction_y = var->player.direction_x * sin(change_angle) 
    + var->player.direction_y * cos(change_angle);
    var->camerax = var->camerax * cos(change_angle) 
    - var->cameray * sin(change_angle);
    var->cameray = var->camerax * sin(change_angle) 
    + var->cameray * cos(change_angle); 
}