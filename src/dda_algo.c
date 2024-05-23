/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:28:20 by mwu               #+#    #+#             */
/*   Updated: 2024/05/23 17:37:25 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	set_step_sidedist(t_var *var, t_coordinate ray, t_hit *res)
{
	if (ray.d_x < 0)
	{
		res->step.x = -1;
		res->sidedist.d_x = (var->player.position_x - \
						(int) var->player.position_x) * res->deltadist.d_x;
	}
	else
		res->sidedist.d_x = (1 - var->player.position_x + \
						(int) var->player.position_x) * res->deltadist.d_x;
	if (ray.d_y < 0)
	{
		res->step.y = -1;
		res->sidedist.d_y = (var->player.position_y - \
						(int) var->player.position_y) * res->deltadist.d_y;
	}
	else
		res->sidedist.d_y = (1 - var->player.position_y + \
						(int) var->player.position_y) * res->deltadist.d_y;
}

void	init_hit_value(t_var *var, t_coordinate ray, t_hit *res)
{
	res->deltadist.d_x = __DBL_MAX__;
	res->deltadist.d_y = __DBL_MAX__;
	if (ray.d_x != 0)
		res->deltadist.d_x = fabs(1 / ray.d_x);
	if (ray.d_y != 0)
		res->deltadist.d_y = fabs(1 / ray.d_y);
	res->step.x = 1;
	res->step.y = 1;
	res->sidedist.d_x = 0;
	res->sidedist.d_y = 0;
	set_step_sidedist(var, ray, res);
	res->ray_map.x = (int)var->player.position_x;
	res->ray_map.y = (int)var->player.position_y;
}

t_hit	dda_main_help(t_var *var, t_coordinate ray, t_hit fo)
{
	t_hit	hit;

	hit.pre_dist = fo.pre_dist;
	hit.hit_pos.d_x = var->player.position_x + ray.d_x * fo.pre_dist;
	hit.hit_pos.d_y = var->player.position_y + ray.d_y * fo.pre_dist;
	hit.perpwalldist = fo.pre_dist * (ray.d_x * var->player.dir.d_x + \
	ray.d_y * var->player.dir.d_y);
	if (fo.hit_side == 'E')
	{
		if (ray.d_x > 0)
			hit.hit_side = WEST;
		else
			hit.hit_side = EAST;
	}
	else
	{
		if (ray.d_y > 0)
			hit.hit_side = NORTH;
		else
			hit.hit_side = SOURTH;
	}
	return (hit);
}

t_hit	dda_main(t_var *var, t_coordinate ray)
{
	t_hit	res;
	t_hit	help;

	init_hit_value(var, ray, &help);
	res.hit_side = '5';
	while (res.hit_side == '5')
	{
		if (help.sidedist.d_x < help.sidedist.d_y)
		{
			help.pre_dist = help.sidedist.d_x;
			help.sidedist.d_x += help.deltadist.d_x;
			help.ray_map.x += help.step.x;
			help.hit_side = 'E';
		}
		else
		{
			help.pre_dist = help.sidedist.d_y;
			help.sidedist.d_y += help.deltadist.d_y;
			help.ray_map.y += help.step.y;
			help.hit_side = 'N';
		}
		if (var->map[help.ray_map.y][help.ray_map.x] == '1')
			res = dda_main_help(var, ray, help);
	}
	return (res);
}
