/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:17:42 by cthaler           #+#    #+#             */
/*   Updated: 2024/04/25 15:17:42 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	check_map(float x, float y, char **map)
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
	c->p.angle += c->key_angle;
	if (c->p.angle == 360)
		c->p.angle = 0;
	else if (c->p.angle < 0)
		c->p.angle += 360;
}
