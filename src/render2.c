/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:15:34 by cthaler           #+#    #+#             */
/*   Updated: 2024/04/29 15:15:34 by cthaler          ###   ########.fr       */
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

void	init_main_img(t_var *c)
{
	c->floor_rgb = create_trgb(0, c->floor[0], c->floor[1], c->floor[2]);
	c->ceiling_rgb = create_trgb(0, c->ceil[0], c->ceil[1], c->ceil[2]);
	c->img->img_ptr = mlx_new_image(c->mlx_init_ptr, IMG_W, IMG_H);
	c->img->img_addr = (int *)mlx_get_data_addr(c->img->img_ptr,
		&c->img->bits_per_pixel, &c->img->size_line, &c->img->endian);
}

float	angle_overflow(float angle)
{
	if (angle < 0)
		return (angle + 360);
	else if (angle >= 360)
		return (angle - 360);
	return (angle);
}
