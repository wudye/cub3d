/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:11:02 by mwu               #+#    #+#             */
/*   Updated: 2024/04/22 16:28:05 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	new_map_value(char **map, char **map_copy, int i, int maxi)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		map_copy[i][j] = map[i][j];
		j++;
	}
	while (j < maxi)
	{
		map_copy[i][j] = '2';
		j++;
	}
	map_copy[i][j] = '\0';
}

static void	new_map(char **map, char **map_copy, int maxi, t_var *var)
{
	int	i;
	int	len;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (i == maxi)
		{
			map_copy[i] = ft_strdup(map[i]);
			if (!map_copy[i])
				return (free_double_ptr(map_copy), error_malloc(var));
		}
		else
		{
			map_copy[i] = malloc(sizeof(char) * (maxi + 1));
			if (!map_copy[i])
				return (free_double_ptr(map_copy), error_malloc(var));
			new_map_value(map, map_copy, i, maxi);
		}
		i++;
	}
	map_copy[i] = 0;
}

static int	check_helper(char **map, int len)
{
	int	i;
	int	maxi;

	i = 0;
	maxi = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > maxi)
			maxi = len;
		i++;
	}
	return (maxi);
}

int	check_map_numbers(t_var *var, char **map)
{
	char	**map_copy;
	int		maxi;
	int		len;

	len = double_ft_len(map);
	map_copy = malloc(sizeof(char *) * (len + 1));
	if (!map_copy)
		error_malloc(var);
	maxi = check_helper(map, len);
	new_map(map, map_copy, maxi, var);
	if (handle_spaces(map_copy, var) == 1)
		return (free_double_ptr(map_copy), 1);
	if (handle_walls(var, map) == 1)
		return (free_double_ptr(map_copy), 1);
// if in the subject the map valid, this condition should remove
// 0 should be surrronded by 1 or not
	if (handle_inner_zero(map_copy, var) == 1)
		return (free_double_ptr(map_copy), 1);
	free_double_ptr(map_copy);
	return (0);
}
