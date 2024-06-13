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
/* old
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
*/

bool	check_space_surround(int i, int j, char **map)
{
	int	max_row;
	int	len;

	len = double_ft_len(map) - 1;
	max_row = ft_strlen(map[0]) - 1;
	if (map[i][j] == '2')
		return (false);
	else if (map[i][j] == '0' || ft_strchr(PLAYER, map[i][j]))
	{
		if (i + 1 >= 0 && i +1 <= len && j >= 0 && j <= max_row)
			return (check_space_surround(i + 1, j, map));
		if (i - 1 >= 0 && i - 1 <= len && j >= 0 && j <= max_row)
			return (check_space_surround(i - 1, j, map));
		if (i >= 0 && i <= len && j + 1 >= 0 && j + 1 <= max_row)
			return (check_space_surround(i, j + 1, map));
		if (i >= 0 && i <= len && j - 1 >= 0 && j - 1 <= max_row)
			return (check_space_surround(i, j - 1, map));
	}
	return (true);
}

bool	player_flood_fill(int i, int j, char **map)
{
	int	max_row;
	int	len;

	len = double_ft_len(map) - 1;
	max_row = ft_strlen(map[0]) - 1;
	if (map[i][j] == '2')
		return (false);
	else if (map[i][j] == '0')
	{
		if (i + 1 >= 0 && i +1 <= len && j >= 0 && j <= max_row)
			return (check_space_surround(i + 1, j, map));
		if (i - 1 >= 0 && i - 1 <= len && j >= 0 && j <= max_row)
			return (check_space_surround(i - 1, j, map));
		if (i >= 0 && i <= len && j + 1 >= 0 && j + 1 <= max_row)
			return (check_space_surround(i, j + 1, map));
		if (i >= 0 && i <= len && j - 1 >= 0 && j - 1 <= max_row)
			return (check_space_surround(i, j - 1, map));
	}
	return (true);
}

bool	check_player_help(int i, int j, char **map)
{
	if (player_flood_fill(i + 1, j, map) == false)
		return (ft_putstr_fd("Error player surround\n", 2), false);
	if (player_flood_fill(i - 1, j, map) == false)
		return (ft_putstr_fd("Error player surround\n", 2), false);
	if (player_flood_fill(i, j + 1, map) == false)
		return (ft_putstr_fd("Error player surround\n", 2), false);
	if (player_flood_fill(i, j - 1, map) == false)
		return (ft_putstr_fd("Error player surround\n", 2), false);
	return (true);
}

bool	check_player_surround(char **map)
{
	int	i;
	int	j;
	int	max_row;
	int	len;

	len = double_ft_len(map) - 1;
	max_row = ft_strlen(map[0]) - 1;
	i = 1;
	while (i < len)
	{
		j = 1;
		while (j < max_row)
		{
			if (ft_strchr(PLAYER, map[i][j]))
			{
				if (check_player_help(i, j, map) == false)
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
