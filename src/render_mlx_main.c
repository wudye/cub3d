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

	var->win_init_ptr = mlx_new_window(var->mlx_init_ptr, 1280, 800, "cub3D");
	if (!var->mlx_init_ptr)
		return (err_return_info("Error win_ptr fail", var));
    mlx_loop(var->mlx_init_ptr);
	return (0);
}
