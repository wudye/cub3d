/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_set_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:20:18 by mwu               #+#    #+#             */
/*   Updated: 2024/05/23 18:38:35 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	set_player_direction(t_var *var)
{
	if (var->player.player_dir == 'N')
	{
		var->player.dir.d_x = 0.0;
		var->player.dir.d_y = -1.0;
	}
	else if (var->player.player_dir == 'S')
	{
		var->player.dir.d_x = 0.0;
		var->player.dir.d_y = 1.0;
	}
	else if (var->player.player_dir == 'E')
	{
		var->player.dir.d_x = 1.0;
		var->player.dir.d_y = 0.0;
	}
	else if (var->player.player_dir == 'W')
	{
		var->player.dir.d_x = -1.0;
		var->player.dir.d_y = 0.0;
	}
}
