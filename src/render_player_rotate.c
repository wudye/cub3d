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
void player_left_rotate(t_var *var)
{
    (void)var;
}

void player_right_rotate(t_var *var)
{
    (void)var;
}