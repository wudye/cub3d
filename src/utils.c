/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:18:56 by cthaler           #+#    #+#             */
/*   Updated: 2024/04/22 13:18:58 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	if (arr)
		while (arr[i])
			i++;
	return (i);
}

int	check_bounds(float x, float y, char **map)
{
	if (x < 0 || y < 0 || y >= arr_len(map)
		|| x >= (int)ft_strlen(map[(int)y]))
		return (1);
	return (0);
}