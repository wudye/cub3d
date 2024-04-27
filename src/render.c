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

void	draw_pixels(t_img1 *img, int x, int h, int w)
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

int	check_map(float x, float y, char **map)
{
	if (map[(int)y][(int)x] == '1')
		return (1);
	else if (x > (int)x && (check_bounds((int)x + 1, (int)y, map)
		|| map[(int)y][(int)x + 1] == '1'))
		return (1);
	else if (y > (int)y && (check_bounds(x, y + 1, map)
		|| map[(int)y + 1][(int)x] == '1'))
		return (1);
	else if (x > (int)x && y > (int)y && (check_bounds((int)x + 1, (int)y, map)
		|| check_bounds((int)x, (int)y + 1, map)
		|| map[(int)y + 1][(int)x + 1] == '1'))
		return (1);
	return (0);
}
void	move_player(t_var *c)
{
	float	x;
	float	y;
	//if (c->key_pos)
	//{
		x = c->p.x - (cos(rad(c->p.angle)) * c->key_pos * 0.05);
		y = c->p.y - (sin(rad(c->p.angle)) * c->key_pos * 0.05);
		if (!check_bounds(x, y, c->map) && !check_map(x, y, c->map))
		{
			if (x - 0.04 < (int)x)
				c->p.x = (int)x;
			else
				c->p.x = x;
			if (y - 0.04 < (int)y)
				c->p.y = (int)y;
			else
				c->p.y = y;
		printf("x: %f y: %f angle: %f pos: %d\n", x, y, c->p.angle, c->key_pos);
		}
	//}
	c->p.angle += c->key_angle;
	if (c->p.angle == 360)
		c->p.angle = 0;
	else if (c->p.angle < 0)
		c->p.angle += 360;
}

int	render_frame(t_var *c)
{
	move_player(c);
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
//if (c->test < 60 && ++c->test)
	//printf("dist: %f x: %f y: %f angle: %f\n", c->r.dist, c->r.x, c->r.y, angle);
		//printf("offset: %f\n", angle);
		//printf("new angle: %f\n", new_angle(c->p.angle + offset));
		//printf("new dist: %f\n", c->r.dist);
			c->r.dist = c->r.dist * cos(rad(fabs(offset)));
			wallH = IMG_H / c->r.dist;
			if (wallH > IMG_H)
				wallH = IMG_H;
		}
		if (wallH)
			draw_pixels(c->img, x_start, wallH, draw_Dist);
		x_start += draw_Dist;
		offset++;
	}
		//if (c->test == 60 && ++c->test)
		//	printf("p_x: %f p_y: %f\n", c->p.x, c->p.y);
	mlx_put_image_to_window(c->mlx_init_ptr,
		c->win_init_ptr, c->img->img_ptr, 0, 0);
	mlx_destroy_image(c->mlx_init_ptr, c->img->img_ptr);
	usleep(9000);
	return (0);
}
