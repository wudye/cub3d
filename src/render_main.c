/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mlx_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:42:34 by mwu               #+#    #+#             */
/*   Updated: 2024/05/02 13:47:46 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
// static void	render_init_var(t_var *var)
// {
// 	var->floor_rgb = change_int_to_rgb(var->floor[0], var->floor[1], var->floor[2]);
// 	var->ceiling_rgb = change_int_to_rgb(var->ceil[0], var->ceil[1], var->ceil[2]);

// }



static void init_render_part(t_var *var)
{
    var->map_height = double_ft_len(var->map);
    var->map_width = longest_colum(var->map);
    set_player_direction(var);
    var->win_init_ptr = mlx_new_window(var->mlx_init_ptr, IMG_W, IMG_H, "cub3D");
	if (!var->mlx_init_ptr)
		return (error_malloc(var));
    var->img->img_ptr = mlx_new_image(var->mlx_init_ptr, IMG_W, IMG_H);
	var->img->img_addr =  mlx_get_data_addr(var->img->img_ptr, &(var->img->bits_per_pixel),
			&(var->img->size_line), &(var->img->endian));
    var->ren = malloc(sizeof(t_render));
    if (!var->ren)
        error_malloc(var);
    value_in_render(var);
}

int	render_mlx(t_var *var)
{

    init_render_part(var);

    // set_camera_value(var);
	mlx_hook(var->win_init_ptr, 17, 0, close_window, var);
    // mlx_hook(var->win_init_ptr, 2, (1L << 0), esc_exit, var);
    mlx_hook(var->win_init_ptr, 2, (1L << 0), key_pressed, var);
    mlx_hook(var->win_init_ptr, 3, (1L << 1), key_released, var);
	// mlx_hook(var->win_init_ptr, 6, (1L << 6), bonus_mouse, var);

	mlx_loop_hook(var->mlx_init_ptr, loop_in_render, var);
	mlx_loop(var->mlx_init_ptr);
    free_var(var);
	return (0);
}
