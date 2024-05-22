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





static void reset_vector_value(t_coordinate *src, double change)
{
    double  ss;
    double  cc;
    t_coordinate temp;
    
    temp.d_x = src->d_x;
    temp.d_y = src->d_y;
    ss = sinf(change);
    cc = cosf(change);
    src->d_x = temp.d_x * cc - temp.d_y * ss;
    src->d_y = temp.d_x * ss + temp.d_y * cc;
}


void player_rotate(t_var *var, double change)
{
    int i;
    double  degree;
    degree = M_PI / 90;

    change *= degree;
    i = 0;
    reset_vector_value(&var->player.dir, change);
    reset_vector_value(&var->ren->left_side_ray, change);
    reset_vector_value(&var->ren->right_side_ray, change);
    // printf("%f %f\n", var->player.direction_x, var->player.direction_y);
    while (i < IMG_W)
    {
        reset_vector_value(&var->ren->rays[i], change);
        i++;
    }
    hit_value_set(var);

}
int	bonus_mouse(int x, int y, t_var *var)
{
	if (x > var->ren->mouse_xy.x)
		player_rotate(var, 0.9);
	else
		player_rotate(var, -0.9);
	var->ren->mouse_xy.x = x;
	var->ren->mouse_xy.y = y;
	return (0);
}

// void	rotate_player(t_cub3d *game, float direction)
// {
// 	float	angle;
// 	int		n_rays;
// 	float	sin_cos[2];

    
// 	angle = M_PI / (180 / 2);
// 	n_rays = 0;
// 	sin_cos[0] = sinf(angle * direction);
// 	sin_cos[1] = cosf(angle * direction);
// 	rotate_vector(sin_cos[0], sin_cos[1], &game->player.dir);
// 	rotate_vector(sin_cos[0], sin_cos[1], &game->player.fov_vec[0]);
// 	rotate_vector(sin_cos[0], sin_cos[1], &game->player.fov_vec[1]);
// 	while (n_rays < game->player.n_rays)
// 	{
// 		rotate_vector(sin_cos[0], sin_cos[1], &game->player.rays[n_rays]);
// 		n_rays++;
// 	}
// 	set_collisions(game);
// }



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