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

/*
Numbers returned by this function can be passed as the color parameter
 in the TextColor or TextColorRemove functions. 
 The RGB function uses the following formula to calculate the result:
red * 2562 + green * 256 + blue 
where 2562 = 65536

    - Red component   : bits 24-31 (hexadecimal mask `0xff000000`)
    - Green component : bits 16-23 (hexadecimal mask `0x00ff0000`)
    - Blue component  : bits  8-15 (hexadecimal mask `0x0000ff00`)
using binary
	return (t << 24 | r << 16 | g << 8 | b);

*/
int	change_int_to_rgb(int r, int g, int b)
{
    return (r * 256 * 256 + g * 256 + b);
    
}