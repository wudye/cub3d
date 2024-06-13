/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:11:02 by mwu               #+#    #+#             */
/*   Updated: 2024/06/13 12:49:34 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static bool	space_check_surrond_help(char **map_copy, int i, int j)
{
	if (check_space_surround(i + 1, j, map_copy) == false)
		return (ft_putstr_fd("Error in space\n", 2), false);
	if (check_space_surround(i - 1, j, map_copy) == false)
		return (ft_putstr_fd("Error in space\n", 2), false);
	if (check_space_surround(i, j + 1, map_copy) == false)
		return (ft_putstr_fd("Error in space\n", 2), false);
	if (check_space_surround(i, j - 1, map_copy) == false)
		return (ft_putstr_fd("Error in space\n", 2), false);
	return (true);
}

static bool	space_check_surrond(char **map, char **map_copy)
{
	int	max_row;
	int	len;
	int	i;
	int	j;

	len = double_ft_len(map) - 1;
	max_row = ft_strlen(map_copy[0]) - 1;
	i = 1;
	while (i < len)
	{
		j = 1;
		while (j < max_row)
		{
			if (map_copy[i][j] == '0')
			{
				if (space_check_surrond_help(map_copy, i, j) == false)
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

static int	check_map_helper(char **map_copy, \
				t_var *var, char **map)
{
	if (check_four_walls(map) == false)
		return (ft_putstr_fd("Error in walls\n", 2), 1);
	put_wall_two(map_copy);
	if (space_check_surrond(map, map_copy) == false)
		return (1);
	if (check_player_surround(map_copy) == false)
		return (ft_putstr_fd("Error in player\n", 2), 1);
	if (set_player_value(map, var) == 1)
		return (1);
	return (0);
}

int	check_map_numbers(t_var *var, char **map)
{
	int		len;
	int		maxi;
	char	**map_copy;

	len = double_ft_len(map);
	map_copy = malloc(sizeof(char *) * (len + 1));
	if (!map_copy)
		return (error_malloc(var), 1);
	maxi = check_helper(map, len);
	set_map_copy(map, map_copy, maxi, var);
	if (check_map_helper(map_copy, var, map) == 1)
		return (free_double_ptr(map_copy), \
		err_return_info("Erorr map", var), 1);
	free_double_ptr(map_copy);
	return (0);
}
