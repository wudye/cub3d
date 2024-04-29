/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mlx_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:42:34 by mwu               #+#    #+#             */
/*   Updated: 2024/04/22 18:43:00 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	render_mlx(t_var *var)
{
	//t_img1	img;

	int i = 0;
	while (var->map[i])
	{
		printf("%s\n", var->map[i++]);
	}
	var->win_init_ptr = mlx_new_window(var->mlx_init_ptr, IMG_W, IMG_H, "cub3D");
	if (!var->mlx_init_ptr)
		return (err_return_info("Error win_ptr fail", var));
	//var->img = (&img);
	var->key_angle = 0;
	var->key_pos = 0;
	var->p.x = var->player_x;
	var->p.y = var->player_y;
	var->p.angle = var->angle;
	init_main_img(var);
//printf("x: %f, y: %f, angle: %d\n", var->p.x, var->p.y, var->p.angle);
	mlx_hook(var->win_init_ptr, 17, 0, close_window, var);
	mlx_hook(var->win_init_ptr, 2, 1L << 0, key_press, var);
	mlx_hook(var->win_init_ptr, 3, 1L << 1, key_release, var);
	mlx_loop_hook(var->mlx_init_ptr, render_frame, var);
	
	mlx_loop(var->mlx_init_ptr);
	return (0);
}
