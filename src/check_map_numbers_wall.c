/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_numbers_wall.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:41:55 by mwu               #+#    #+#             */
/*   Updated: 2024/04/26 12:28:26 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

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
/*
static float	angle(char c)
{
	if (c == 'N')
		return (90);
	else if (c == 'S')
		return (270);
	else if (c == 'E')
		return (180);
	else if (c == 'W')
		return (0);
	return (0);
}

static int	set_player_value(char **map, t_var *var, int i, int num)
{
	int	j;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr(PLAYER, map[i][j]))
			{
				var->player_x = i;
				var->player_y = j;
				var->angle = angle(map[i][j]);
				num += 1;
			}
			else if (map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != '0' \
							&& !ft_strchr(PLAYER, map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	if (num != 1)
		return (1);
	return (0);
}

int	handle_walls(t_var *var, char **map)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (handle_first_end_line(map) == 1)
		return (err_return_info("Error map walls wrong", var), 1);
	if (handle_mid_lines(map) == 1)
		return (err_return_info("Error map walls wrong", var), 1);
	if (set_player_value(map, var, i, num) == 1)
		return (err_return_info("Erorr player fail", var), 1);
	return (0);
}
*/

int	handle_walls(t_var *var, char **map)
{

	if (handle_first_end_line(map) == 1)
		return (err_return_info("Error map walls wrong", var), 1);
	if (handle_mid_lines(map) == 1)
		return (err_return_info("Error map walls wrong", var), 1);
	return (0);
}