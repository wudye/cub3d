/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:09:31 by cthaler           #+#    #+#             */
/*   Updated: 2024/04/25 13:09:33 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

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
