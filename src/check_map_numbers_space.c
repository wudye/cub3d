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

/* old code
static bool	dfs_al(char **map, int j, int k)
{
	int	row;
	int	col;

	row = double_ft_len(map);
	col = ft_strlen(map[0]);
	if ((j - 1 >= 0 && j + 1 < row && k - 1 >= 0 && k + 1 < col) \
	&& (map[j - 1][k] == '0' || map[j + 1][k] == '0' \
	|| map[j][k - 1] == '0' || map[j][k + 1] == '0'))
		return (false);
	else if (j + 1 == row && k - 1 >= 0 && k + 1 < col
		&& (map[j - 1][k] == '0' || map[j][k - 1] == '0'
				|| map[j][k + 1] == '0'))
		return (false);
	else if ((j - 1 >= 0 && j + 1 < row && k + 1 == col)
		&& (map[j - 1][k] == '0' || map[j + 1][k] == '0'
				|| map[j][k - 1] == '0'))
		return (false);
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
*/

void	set_map_copy(char **map, char **map_copy, int maxi, t_var *var)
{
	int	len;
	int	i;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		map_copy[i] = malloc(sizeof(char) * (maxi + 1));
		if (!map_copy[i])
			error_malloc(var);
		map_copy_help(map[i], map_copy[i], maxi);
		i++;
	}
	map_copy[i] = 0;
}

void	dfs(char **map, int i, int j, char target)
{
	int	max_row;
	int	len;

	len = double_ft_len(map) - 1;
	max_row = ft_strlen(map[0]) - 1;
	if (i >= 0 && i <= len && j >= 0 && j <= max_row && map[i][j] == ' ')
	{
		map[i][j] = '2';
		if (i + 1 >= 0 && i +1 <= len && j >= 0 && j <= max_row)
			dfs(map, i + 1, j, target);
		if (i - 1 >= 0 && i -1 <= len && j >= 0 && j <= max_row)
			dfs(map, i - 1, j, target);
		if (i >= 0 && i <= len && j + 1 >= 0 && j +1 <= max_row)
			dfs(map, i, j + 1, target);
		if (i >= 0 && i <= len && j - 1 >= 0 && j - 1 <= max_row)
			dfs(map, i, j - 1, target);
	}
}

void	put_wall_two(char **map)
{
	int	max_row;
	int	len;
	int	j;

	len = double_ft_len(map) - 1;
	max_row = ft_strlen(map[0]) - 1;
	j = 0;
	while (j <= max_row)
	{
		if (map[0][j] == ' ')
			dfs(map, 0, j, '1');
		if (map[len][j] == ' ')
			dfs(map, len, j, '1');
		j++;
	}
	j = 0;
	while (j <= len)
	{
		if (map[j][0] == ' ')
			dfs(map, j, 0, '1');
		if (map[j][max_row] == ' ')
			dfs(map, j, max_row, '1');
		j++;
	}
}

bool	check_four_walls_help(int line, char **map, int flag)
{
	int		len;
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strtrim(map[line], " ");
	len = ft_strlen(temp) - 1;
	if (flag == 1)
	{
		if (temp[0] != '1' || temp[len] != '1')
			return (free(temp), false);
	}
	if (flag == 0)
	{
		while (temp[i])
		{
			if (temp[i] != '1' && temp[i] != ' ')
				return (free(temp), false);
			i++;
		}
	}
	free(temp);
	return (true);
}

bool	check_four_walls(char **map)
{
	int	len;
	int	i;

	len = double_ft_len(map) - 1;
	if (!check_four_walls_help(0, map, 0) \
					|| !check_four_walls_help(len, map, 0))
		return (false);
	i = 1;
	while (i <= len - 1)
	{
		if (check_four_walls_help(i, map, 1) == false)
			return (false);
		i++;
	}
	return (true);
}
