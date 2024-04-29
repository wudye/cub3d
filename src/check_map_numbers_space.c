/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_numbers_space.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:28:53 by mwu               #+#    #+#             */
/*   Updated: 2024/04/22 16:41:11 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static bool	dfs_al(char **map, int j, int k)
{
	int	row;
	int	col;

	row = double_ft_len(map);
	col = ft_strlen(map[0]);
	if ((j - 1 >= 0 && j + 1 < row && k - 1 >= 0 && k + 1 < col) \
	&& (map[j - 1][k] == '0' || map[j + 1][k] == '0' \
	|| map[j][k - 1] == '0' || map[j][k + 1] == '0'))
		return (printf("test\n"), false);
	else if (j + 1 == row && k - 1 >= 0 && k + 1 < col
		&& (map[j - 1][k] == '0' || map[j][k - 1] == '0'
				|| map[j][k + 1] == '0'))
		return (printf("test1\n"), false);
	else if ((j - 1 >= 0 && j + 1 < row && k + 1 == col)
		&& (map[j - 1][k] == '0' || map[j + 1][k] == '0'
				|| map[j][k - 1] == '0'))
		return (printf("test2\n"), false);
	return (true);
}

int	handle_spaces(char **map, t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
			{
				if (dfs_al(map, i, j) != true)
					return (err_return_info("Error map spaces wrong", var));
				else
					map[i][j] = '1';
			}
			j++;
		}
		i++;
	}
	return (0);
}

// this part has to discuss to remove or not
static bool	dfs_zero(int i, int j, char **str)
{
	int	row;
	int	col;

	row = double_ft_len(str);
	col = ft_strlen(str[0]);
	if (str[i][j] == '2' && (i + 1 <= row
							|| i - 1 >= -1 || j + 1 <= col || j - 1 >= -1))
		return (false);
	return (true);
}

int	handle_inner_zero(char **map_copy, t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == '0')
			{
				if (!(dfs_zero(i + 1, j, map_copy) \
				&& dfs_zero(i - 1, j, map_copy) && dfs_zero(i, j + 1, map_copy) \
										&& dfs_zero(i, j - 1, map_copy)))
					return (err_return_info("Error 0 not closed wall", var));
			}
			j++;
		}
		i++;
	}
	return (0);
}
