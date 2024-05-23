/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_numbers_wall.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:41:55 by mwu               #+#    #+#             */
/*   Updated: 2024/05/23 17:27:08 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	set_player_value(char **map, t_var *var)
{
	int	i;
	int	j;
	int	num;

	num = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr(PLAYER, map[i][j]))
			{
				var->player.position_y = i + 0.5;
				var->player.position_x = j + 0.5;
				var->player.player_dir = map[i][j];
				num += 1;
			}
			j++;
		}
		i++;
	}
	if (num != 1)
		return (1);
	return (0);
}

static int	handle_mid_lines(char **map)
{
	int	i;
	int	e;
	int	len;

	e = double_ft_len(map) - 1;
	i = 1;
	while (i < e)
	{
		len = ft_strlen(map[i]) - 1;
		while (len > 0 && map[i][len] \
						&& (map[i][len] == ' ' || map[i][len] == '\t'))
			len--;
		if (map[i][0] != '1' || map[i][len] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	handle_first_end_line(char **map)
{
	int	e;
	int	j;

	j = 0;
	e = double_ft_len(map) - 1;
	while (map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != ' ')
			return (1);
		j++;
	}
	j = 0;
	while (map[e][j])
	{
		if (map[e][j] != '1' && map[e][j] != ' ')
			return (1);
		j++;
	}
	return (0);
}

int	handle_walls(t_var *var, char **map)
{
	if (handle_first_end_line(map) == 1)
		return (err_return_info("Error map walls wrong", var), 1);
	if (handle_mid_lines(map) == 1)
		return (err_return_info("Error map walls wrong", var), 1);
	return (0);
}
