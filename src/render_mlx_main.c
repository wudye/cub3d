/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mlx_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:42:34 by mwu               #+#    #+#             */
/*   Updated: 2024/04/26 14:35:19 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	print_map_mess(t_var *var)
{
	int	i;

	i = 0;
	while (var->texture[i])
	{
		printf("%s\n", var->texture[i]);
		i++;
	}
	i = 0;
	while(var->map[i])
	{
		printf("%s", var->map[i]);
		i++;
	}
}

int	render_mlx(t_var *var)
{
	t_img       img;
    t_camera    temp_camera;


    init_camera(var, &temp_camera); 
	print_map_mess(var);

	var->win_init_ptr = mlx_new_window(var->mlx_init_ptr, IMG_W, IMG_H, "cub3D");
	if (!var->mlx_init_ptr)
		return (err_return_info("Error win_ptr fail", var));
	var->img = (&img);
	var->key_press = 0;
	var->p.x = var->player_x;
	var->p.y = var->player_y;
	var->p.angle = var->angle;
	// my try
    // 6	MotionNotify
    // (1L<<6)	PointerMotionMas
    // void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
    // ON_MOUSEMOVE	6	int (*f)(int x, int y, void *param)
	mlx_hook(var->win_init_ptr, 6, 1L<<6, mouse_hook, var);
    mlx_loop_hook(var->mlx_init_ptr, window_loop, var);
    mlx_loop(var->mlx_init_ptr);

	/*
// printf("test ->x: %f, y: %f, angle: %d\n", var->p.x, var->p.y, var->p.angle);
	mlx_hook(var->win_init_ptr, 17, 0, close_window, var);
	mlx_hook(var->win_init_ptr, 2, 1L << 0, key_press, var);
	mlx_loop_hook(var->mlx_init_ptr, render_frame, var);
	mlx_loop(var->mlx_init_ptr);
	*/

	return (0);
}
