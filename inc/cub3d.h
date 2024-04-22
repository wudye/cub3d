/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:45:02 by cthaler           #+#    #+#             */
/*   Updated: 2024/04/17 13:45:03 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_ray
{
	float x;
	float y;
	float dist;
	int angle;
	
}		t_ray;

typedef struct	s_player
{
	float x;
	float y;
	int angle;
	
}		t_player;

int	arr_len(char **arr);
int	check_bounds(int x, int y, char **map);
float	rad(float degree);

#endif