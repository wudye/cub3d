/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:30:31 by cthaler           #+#    #+#             */
/*   Updated: 2024/05/30 21:30:33 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	copy_map(char **map, char **map_copy)
{
	int	i;

	i = 0;
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			--i;
			while (i >= 0)
				free(map_copy[i--]);
			return (free(map_copy), 1);
		}
		i++;
	}
	map_copy[i] = 0;
	return (0);
}

static void	flood_fill(char **map, int x, int y)
{
	if (y >= 0 && x >= 0 && (map[y] && (int)ft_strlen(map[y]) > x)
		&& (map[y][x] == '0' || map[y][x] == ' ' || map[y][x] == 'N'
	 || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W'))
	{
		if (map[y][x] == ' ')
			map[y][x] = '2';
		else
			map[y][x] = '1';
		flood_fill(map, x - 1, y);
		flood_fill(map, x + 1, y);
		flood_fill(map, x, y - 1);
		flood_fill(map, x, y + 1);
	}
}

static int	check_flood_res(char **map, t_var *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			if (map[i][j++] == '2')
				return (free_double_ptr(map),
					err_return_info("Error invalid map", var));
		i++;
	}
	return (free_double_ptr(map), 0);
}

int	check_map_floodfill(t_var *var, char **map)
{
	char	**map_copy;
	int		x;
	int		y;

	y = 0;
	map_copy = malloc(sizeof(map_copy) * (double_ft_len(map) + 1));
	if (!map_copy)
		error_malloc(var);
	if (copy_map(map, map_copy))
		error_malloc(var);
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == '0' || map_copy[y][x] == 'N'
				|| map_copy[y][x] == 'S' || map_copy[y][x] == 'E'
				|| map_copy[y][x] == 'W')
				flood_fill(map_copy, x, y);
			x++;
		}
		y++;
	}
	return (check_flood_res(map_copy, var));
}
