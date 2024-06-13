/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_in_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:46:42 by mwu               #+#    #+#             */
/*   Updated: 2024/05/23 17:53:09 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

t_img	*set_texture_ptr(t_var *var, char c)
{
	if (c == NORTH)
		return (var->north);
	else if (c == SOURTH)
	{
		return (var->sourth);
	}
	else if (c == WEST)
	{
		return (var->west);
	}
	else
		return (var->east);
}

t_coordinate	cal_texture(t_hit *hit, t_draw draw, int n)
{
	t_coordinate	dist;

	dist.d_x = hit->hit_pos.d_x - (int)hit->hit_pos.d_x;
	dist.d_x += hit->hit_pos.d_y - (int)hit->hit_pos.d_y;
	dist.d_y = (n - draw.start) / (draw.high);
	return (dist);
}

void	draw_map(t_var *var, t_step *st_xy, t_draw draw, t_hit *hit)
{
	int				height;
	t_img			*tex;
	unsigned int	*data;
	t_coordinate	tex_range;

	if (draw.end < IMG_H)
		height = draw.end;
	else
		height = IMG_H;
	tex = set_texture_ptr(var, hit->hit_side);
	while (st_xy->y < height)
	{
		data = pixel_ptr(var->img, st_xy->x, st_xy->y);
		tex_range = cal_texture(hit, draw, st_xy->y);
		if (hit->hit_side == 'N' || hit->hit_side == 'E')
			*data = texture_pixel_e_n(tex, tex_range);
		else
			*data = texture_pixel_s_w(tex, tex_range);
		st_xy->y++;
	}
}

void	draw_all(t_var *var, t_step *st_xy, t_draw draw, t_hit *hit)
{
	unsigned int	*data;
	unsigned int	color;

	color = change_int_to_rgb(var->ceil[0], var->ceil[1], var->ceil[2]);
	while (st_xy->y < draw.start)
	{
		data = pixel_ptr(var->img, st_xy->x, st_xy->y);
		*data = color;
		st_xy->y++;
	}
	draw_map(var, st_xy, draw, hit);
	color = change_int_to_rgb(var->floor[0], var->floor[1], var->floor[2]);
	while (st_xy->y < IMG_H)
	{
		data = pixel_ptr(var->img, st_xy->x, st_xy->y);
		*data = color;
		st_xy->y++;
	}
}

int	loop_in_render(t_var *var)
{
	t_step	st_xy;
	t_draw	draw;
	t_hit	hit;

	move_player(var);
	st_xy.x = 0;
	while (st_xy.x < IMG_W)
	{
		st_xy.y = 0;
		hit = var->ren->hits[st_xy.x];
		draw.high = IMG_H / hit.perpwalldist;
		draw.start = (IMG_H - draw.high) / 2;
		draw.end = draw.start + draw.high;
		draw_all(var, &st_xy, draw, &hit);
		st_xy.x++;
	}
	mlx_put_image_to_window(var->mlx_init_ptr, \
					var->win_init_ptr, var->img->img_ptr, 0, 0);
	return (0);
}
