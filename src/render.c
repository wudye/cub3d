/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:31:57 by cthaler           #+#    #+#             */
/*   Updated: 2024/04/25 10:31:59 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	draw_pixels(t_var *var, int x, int h, int w)
{
	int	x2;
	int	y;
	int	draw_h;
	t_img	*img;

	img = var->img;
	//later use wall textures
	int test_rgb;
	if (!var->r.vert && var->r.angle > 0 && var->r.angle < 180)
		test_rgb = create_trgb(0, 128, 255, 26);
	else if (!var->r.vert && var->r.angle > 180 && var->r.angle < 360)
		test_rgb = create_trgb(0, 0, 255, 255);
	else if (var->r.vert && var->r.angle > 90 && var->r.angle < 270)
		test_rgb = create_trgb(0, 255, 128, 26);
	else
		test_rgb = create_trgb(0, 255, 0, 255);
	y = IMG_H / 2 + h / 2;
	draw_h = 0;
	while (y >= 0 && draw_h < h)
	{
		x2 = 0;
		while (x2 + x < IMG_W && x2 < w)
		{
			img->img_addr[y * IMG_W + x2 + x] = test_rgb;
			x2++;
		}
		draw_h++;
		y--;
	}
}

static void	render_frame2(t_var *c, int x_start, int draw_Dist, float offset)
{
	int	wallH;
	float	angle;

	while (offset < 30)
	{
		wallH = 0;
		angle = angle_overflow(c->p.angle + offset);
		calc_ray(&c->p, &c->r, angle, c->map);
		if (c->r.dist > 0)
		{
			c->r.dist = c->r.dist * cos(rad(fabs(offset)));
			wallH = IMG_H / c->r.dist;
			if (wallH > IMG_H)
				wallH = IMG_H;
		}
		if (wallH)
			draw_pixels(c, x_start, wallH, draw_Dist);
		x_start += draw_Dist;
		offset++;
	}
}

int	render_frame(t_var *c)
{
	int	x_start;
	int	draw_Dist;
	float	offset;

	create_floor(c, c->img, IMG_W, IMG_H);
	offset = -30;
	draw_Dist = IMG_W / 60;
	x_start = 0;
	render_frame2(c, x_start, draw_Dist, offset);
	mlx_put_image_to_window(c->mlx_init_ptr,
		c->win_init_ptr, c->img->img_ptr, 0, 0);
	move_player(c);
	usleep(9000);
	return (0);
}
