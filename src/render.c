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

#include "../inc/cub3D.h"

void	create_floor(t_var *c, t_img *img, int width, int height)
{
	int	w;
	int	h;

	h = 0;
	while (h < height)
	{
		w = 0;
		while (w < width)
		{
			if ((h + 1) * 2 < height)
				img->img_addr[h * width + w] = c->ceiling_rgb;
			else
				img->img_addr[h * width + w] = c->floor_rgb;
			w++;
		}
		h++;
	}
}

void	draw_pixels(t_img *img, int x, int h, int w)
{
	int	x2;
	int	y;
	
	int test_rgb = create_trgb(0, 235, 26, 26);
	
	y = IMG_H / 2 + h / 2;
	int test = 0;
	while (y >= 0 && test < h)
	{
		x2 = 0;
		while (x2 + x < IMG_W && x2 < w)
		{
			img->img_addr[y * IMG_W + x2 + x] = test_rgb;
			x2++;
		}
		test++;
		y--;
	}
}

void	init_img(t_var *c)
{
	c->floor_rgb = create_trgb(0, c->floor[0], c->floor[1], c->floor[2]);
	c->ceiling_rgb = create_trgb(0, c->ceil[0], c->ceil[1], c->ceil[2]);
	c->img->img_ptr = mlx_new_image(c->mlx_init_ptr, IMG_W, IMG_H);
	c->img->img_addr = (int *)mlx_get_data_addr(c->img->img_ptr,
		&c->img->bits_per_pixel, &c->img->size_line, &c->img->endian);
}

float	new_angle(float angle)
{
	if (angle < 0)
		return (fabs(angle - 360));
	else if (angle < 135 && angle > 45)
		return (fabs(90 - angle));
	else if (angle > 135 && angle < 225)
		return (fabs(angle - 180));
	else if (angle > 225 && angle < 315)
		return (fabs(angle - 270));
	//else if (angle > 315)
	//	return (fabs(360 - angle));
	return (angle);
}

int	render_frame(t_var *c)
{
	init_img(c);
	create_floor(c, c->img, IMG_W, IMG_H);
	
	float offset = -30;
	int draw_Dist = IMG_W / 60;
	int x_start = 0;
	while (offset < 30)
	{
		int wallH = 0;
		float angle = c->p.angle + offset;
		if (angle < 0)
			angle += 360;
		else if (angle >= 360)
			angle -= 360;
		//if (!offset)
	//printf("angle: %f\n", angle);
		calc_ray(&c->p, &c->r, angle, c->map);
	//printf("offset: %f\n", offset);
		if (c->r.dist > 0)
		{
		//printf("dist: %f\n", c->r.dist);
		//printf("offset: %f\n", angle);
		//printf("new angle: %f\n", new_angle(c->p.angle + offset));
		//	if (angle && angle != 90 && angle != 180 && angle != 270 )
		//		c->r.dist = c->r.dist
		//			* fabs(cos(rad(new_angle(c->p.angle + offset))));
		//printf("new dist: %f\n", c->r.dist);
			//c->r.dist = c->r.dist * cos(rad(c->p.angle + offset));
			wallH = IMG_H / c->r.dist;
			if (wallH > IMG_H)
				wallH = IMG_H;
		}
		if (wallH)
			draw_pixels(c->img, x_start, wallH, draw_Dist);
		x_start += draw_Dist;
		offset++;
	}
	mlx_put_image_to_window(c->mlx_init_ptr,
		c->win_init_ptr, c->img->img_ptr, 0, 0);
	mlx_destroy_image(c->mlx_init_ptr, c->img->img_ptr);
	if (c->key_press)
		c->p.angle ++;
	if (c->p.angle == 360)
		c->p.angle = 0;
	usleep(9000);
	return (0);
}
