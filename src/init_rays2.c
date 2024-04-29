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

#include "../inc/cub3d.h"

static int	check_map_pos(float x, float y, char **map)
{
	if (!check_bounds(x, y, map) && map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

int	check_hor_map(t_ray *r, char **map)
{
	if (r->angle < 90 && (!check_map_pos(r->x, r->y, map)
		|| (r->y && check_map_pos(r->x, r->y - 1, map))))
		return (0);
	else if ((r->angle > 90 && r->angle < 180) && (!check_map_pos(r->x, r->y, map)
		|| (r->y && check_map_pos(r->x, r->y - 1, map))))
		return (0);
	else if ((r->angle > 180 && r->angle < 270) && (!check_map_pos(r->x, r->y, map)
		|| check_map_pos(r->x, r->y + 1, map)))
		return (0);
	else if (r->angle > 270 && (!check_map_pos(r->x, r->y, map)
		|| check_map_pos(r->x, r->y + 1, map)))
		return (0);
	return (1);
}

int	check_vert_map(t_ray *r, float x, float y, char **map)
{
	if (r->angle < 90 && (!check_map_pos(x, y, map)
		|| (x && check_map_pos(x - 1, y, map))))
		return (0);
	else if ((r->angle > 90 && r->angle < 180) && (!check_map_pos(x, y, map)
		|| check_map_pos(x + 1, y, map)))
		return (0);
	else if ((r->angle > 180 && r->angle < 270) && (!check_map_pos(x, y, map)
		|| check_map_pos(x + 1, y, map)))
		return (0);
	else if (r->angle > 270 && (!check_map_pos(x, y, map)
		|| (x && check_map_pos(x - 1, y, map))))
		return (0);
	return (1);
}
