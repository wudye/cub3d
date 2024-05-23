/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:16:36 by mwu               #+#    #+#             */
/*   Updated: 2024/05/23 18:19:34 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
static void	reset_vector_value(t_coordinate *src, double change)
{
	double			ss;
	double			cc;
	t_coordinate	temp;

	temp.d_x = src->d_x;
	temp.d_y = src->d_y;
	ss = sinf(change);
	cc = cosf(change);
	src->d_x = temp.d_x * cc - temp.d_y * ss;
	src->d_y = temp.d_x * ss + temp.d_y * cc;
}

void	player_rotate(t_var *var, double change)
{
	int		i;
	double	degree;

	degree = M_PI / 90;
	change *= degree;
	i = 0;
	reset_vector_value(&var->player.dir, change);
	reset_vector_value(&var->ren->left_side_ray, change);
	reset_vector_value(&var->ren->right_side_ray, change);
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
