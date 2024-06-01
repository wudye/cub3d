/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:05:33 by mwu               #+#    #+#             */
/*   Updated: 2024/05/23 18:14:51 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	player_up_move(t_var *var)
{
	double	new_posx;
	double	new_posy;

	new_posx = var->player.position_x + var->player.dir.d_x * PLAYER_MOVE;
	new_posy = var->player.position_y + var->player.dir.d_y * PLAYER_MOVE;
	if (var->map[(int)var->player.position_y][(int)new_posx] != '1')
		var->player.position_x += var->player.dir.d_x * PLAYER_MOVE;
	if (var->map[(int)(new_posy - M_D)][(int)var->player.position_x] != '1')
		var->player.position_y += var->player.dir.d_y * PLAYER_MOVE - M_D;
	hit_value_set(var);
}

void	player_down_move(t_var *var)
{
	double	new_posx;
	double	new_posy;

	new_posx = var->player.position_x - var->player.dir.d_x * PLAYER_MOVE;
	new_posy = var->player.position_y - var->player.dir.d_y * PLAYER_MOVE;
	if (var->map[(int)var->player.position_y][(int)new_posx] != '1')
		var->player.position_x -= var->player.dir.d_x * PLAYER_MOVE;
	if (var->map[(int)(new_posy + M_D)][(int)var->player.position_x] != '1')
		var->player.position_y -= var->player.dir.d_y * PLAYER_MOVE + M_D;
	hit_value_set(var);
}

void	player_left_move(t_var *var)
{
	double	new_posx;
	double	new_posy;
	double	new_dirx;
	double	new_diry;

	new_dirx = var->player.dir.d_x * cosf(-M_PI / 2) - M_D - \
var->player.dir.d_y * sinf(-M_PI / 2);
	new_diry = var->player.dir.d_x * sinf(-M_PI / 2) + \
var->player.dir.d_y * cosf(-M_PI / 2);
	new_posx = var->player.position_x + 2 * new_dirx * PLAYER_MOVE;
	new_posy = var->player.position_y + 2 * new_diry * PLAYER_MOVE;
	if (var->map[(int)new_posy][(int)new_posx] == '1')
		return ;
	var->player.position_x += 2 * new_dirx * PLAYER_MOVE;
	var->player.position_y += 2 * new_diry * PLAYER_MOVE;
	hit_value_set(var);
}

void	player_right_move(t_var *var)
{
	double	new_posx;
	double	new_posy;
	double	new_dirx;
	double	new_diry;

	new_dirx = var->player.dir.d_x * cosf(M_PI / 2) + M_D - \
var->player.dir.d_y * sinf(M_PI / 2);
	new_diry = var->player.dir.d_x * sinf(M_PI / 2) + \
var->player.dir.d_y * cosf(M_PI / 2);
	new_posx = var->player.position_x + 2 * new_dirx * PLAYER_MOVE;
	new_posy = var->player.position_y + 2 * new_diry * PLAYER_MOVE;
	if (var->map[(int)new_posy][(int)new_posx] == '1')
		return ;
	var->player.position_x += 2 * new_dirx * PLAYER_MOVE;
	var->player.position_y += 2 * new_diry * PLAYER_MOVE;
	hit_value_set(var);
}

void	move_player(t_var *var)
{
	if (var->move.up_move == 1)
		player_up_move(var);
	else if (var->move.down_move == 1)
		player_down_move(var);
	else if (var->move.left_move == 1)
		player_left_move(var);
	else if (var->move.right_move == 1)
		player_right_move(var);
	else if (var->move.right_rotate == 1)
		player_rotate(var, 0.3);
	else if (var->move.left_rotate == 1)
		player_rotate(var, -0.3);
}
