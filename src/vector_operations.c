/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:34:53 by mwu               #+#    #+#             */
/*   Updated: 2024/05/23 18:37:28 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	coordinate_x_y(double step, t_coordinate *add, t_coordinate src)
{
	add->d_x = src.d_x * step;
	add->d_y = src.d_y * step;
}

void	vectot_rotate_by_angle(t_coordinate *ray, double angle, \
				t_player player, double fov_rat)
{
	float	x;
	float	y;

	x = player.dir.d_x * fov_rat;
	y = player.dir.d_y * fov_rat;
	ray->d_x = x * cosf(angle) - y * sinf(angle);
	ray->d_y = x * sinf(angle) + y * cosf(angle);
}
