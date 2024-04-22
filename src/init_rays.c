/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:01:08 by cthaler           #+#    #+#             */
/*   Updated: 2024/04/22 11:01:10 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

float	convert_angle(t_ray *r, int horizontal)
{
	if (horizontal)
	{
		if (r->angle < 180)
			return (rad(fabs(90.0 - r->angle)));
		else
			return (rad(fabs(270.0 - r->angle)));
	}
	else
	{
		if (r->angle > 90 && r->angle < 270)
			return (rad(fabs(r->angle - 180.0)));
		else if (r->angle > 270)
			return (rad(fabs(r->angle - 360.0)));
	}
	return (rad(r->angle));
}

float	calc_coordinate(t_ray *r, t_player *p, int horizontal, int x)
{
	float	i;

	i = 0;
	if (horizontal)
	{
		if (r->angle < 90 || r->angle > 270)
			i = p->x - tan(convert_angle(r, 1)) * fabs(r->y - p->y);
		else
			i = p->x + tan(convert_angle(r, 1)) * fabs(r->y - p->y);
	}
	else
	{
		if (r->angle < 180)
			i = p->y - tan(convert_angle(r, 0)) * fabs(x - p->x);
		else
			i = p->y + tan(convert_angle(r, 0)) * fabs(x - p->x);
	}
	return (i);
}

int	check_hor_map(t_ray *r, char **map)
{
	if ((r->angle > 270 || r->angle < 90)
		&& !check_bounds(r->x + 1, r->y, map) && !check_bounds(r->x, r->y, map)
		&& ((r->x == (int)r->x && map[(int)r->y][(int)r->x] == '1')
		|| (r->x != (int)r->x && map[(int)r->y][(int)r->x + 1] == '1')))
		return (1);
	else if ((r->angle < 270 && r->angle > 90)
		&& !check_bounds(r->x - 1, r->y, map) && !check_bounds(r->x, r->y, map)
		&& ((r->x == (int)r->x && map[(int)r->y][(int)r->x] == '1')
		|| (r->x != (int)r->x && map[(int)r->y][(int)r->x - 1] == '1')))
		return (1);
	return (0);
}

int	check_vert_map(t_ray *r, float x, float y, char **map)
{
	if (r->angle < 180 && !check_bounds(x, y + 1, map)
		&& !check_bounds(x, y, map)
		&& ((y == (int)y && map[(int)y][(int)x] == '1')
		|| (y != (int)y && map[(int)y + 1][(int)x] == '1')))
		return (1);

	else if (r->angle > 180 && !check_bounds(x, y - 1, map)
		&& !check_bounds(x, y, map)
		&& ((y == (int)y && map[(int)y][(int)x] == '1')
		|| (y != (int)y && map[(int)y - 1][(int)x] == '1')))
		return (1);
	return (0);
}

void	check_horizontal(t_player *p, t_ray *r, char **map)
{
	while (!check_bounds(r->x, r->y, map))
	{
		r->x = calc_coordinate(r, p, 1, 0);
		if (check_hor_map(r, map))
			break ;
		if (r->angle < 180)
			r->y -= 1;
		else
			r->y += 1;
	}
	if (!check_bounds(r->x, r->y, map))
		r->dist = fabs(r->y - p->y) / cos(convert_angle(r, 1));
}

int	check_vertical(t_player *p, t_ray *r, char **map)
{
	float	x;
	float	y;
	float	dist;

	x = (int)p->x;
	y = 0;
	while (!check_bounds(x, y, map))
	{
		y = calc_coordinate(r, p, 0, x);
		if (check_vert_map(r, x, y, map))
			break ;
		if (r->angle < 90 || r->angle > 270)
			x -= 1;
		else
			x += 1;
	}
	dist = fabs(x - p->x) / cos(convert_angle(r, 0));
	if (!check_bounds(x, y, map) && dist && (dist < r->dist || !r->dist))
		return (r->x = x, r->y = y, r->dist = dist, 0);
	return (0);
}

void	calc_ray(t_player *p, t_ray *r, float angle, char **map)
{
	if (angle == 90 || angle == 270 || angle == 0 || angle == 180)
		angle += 0.1;
	r->angle = angle;
	r->x = (int)p->x;
	r->y = (int)p->y;
	r->dist = 0;
	check_horizontal(p, r, map);
	check_vertical(p, r, map);
}
