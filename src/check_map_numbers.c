/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:11:02 by mwu               #+#    #+#             */
/*   Updated: 2024/05/23 17:25:33 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	set_map_copy(char **map, char **map_copy, int maxi, t_var *var)
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

static void	change_map_begin(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '1' && map[i][j] != '0' \
						&& !ft_strchr(PLAYER, map[i][j]))
		{
			map[i][j] = '1';
			j++;
		}
		i++;
	}
}

static char	**reset_map_value(char **map, t_var *var, int len)
{
	int		i;
	char	**map_help;

	i = 0;
	map_help = malloc(sizeof(char *) * (len + 1));
	if (!map_help)
		error_malloc(var);
	while (map[i])
	{
		map_help[i] = ft_strdup(map[i]);
		if (!map_help[i])
		{
			free_double_ptr(map_help);
			error_malloc(var);
		}
		i++;
	}
	map_help[i] = 0;
	return (map_help);
}

static int	check_map_helper(char **map_copy, \
				t_var *var, char **map_help, char **map)
{
	if (handle_spaces(map_copy, var) == 1)
		return (free_double_ptr(map_copy), free_double_ptr(map_help), 1);
	if (handle_inner_zero(map_copy, var) == 1)
		return (free_double_ptr(map_copy), free_double_ptr(map_help), 1);
	if (handle_walls(var, map_help) == 1)
		return (free_double_ptr(map_copy), free_double_ptr(map_help), 1);
	if (set_player_value(map, var) == 1)
		return (free_double_ptr(map_copy), free_double_ptr(map_help), \
						err_return_info("Erorr player fail", var), 1);
	return (0);
}

int	check_map_numbers(t_var *var, char **map)
{
	int		len;
	int		maxi;
	char	**map_copy;
	char	**map_help;

	len = double_ft_len(map);
	map_help = reset_map_value(map, var, len);
	if (check_map_value(var, map_help) == false)
		return (free_double_ptr(map_help), 1);
	map_copy = malloc(sizeof(char *) * (len + 1));
	if (!map_copy)
		error_malloc(var);
	change_map_begin(map_help);
	maxi = check_helper(map_help, len);
	set_map_copy(map_help, map_copy, maxi, var);
	if (check_map_helper(map_copy, var, map_help, map) == 1)
		return (1);
	free_double_ptr(map_copy);
	free_double_ptr(map_help);
	return (0);
}
