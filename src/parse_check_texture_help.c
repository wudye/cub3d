/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_texture_help.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:38:40 by mwu               #+#    #+#             */
/*   Updated: 2024/04/26 12:40:20 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static bool	check_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (false);
		i++;
	}
	return (true);
}

int	check_color_value(char *str, int *color)
{
	char	**split_str;
	int		i;
	int		temp;

	i = 0;
	split_str = ft_split(str, ',');
	if (!split_str)
		return (-1);
	if (double_ft_len(split_str) != 3)
		return (free_double_ptr(split_str), 1);
	while (split_str[i])
	{
		if (check_int(split_str[i]) == false)
			return (free_double_ptr(split_str), 1);
		temp = ft_atoi(split_str[i]);
		if (temp < 0 || temp > 255)
			return (free_double_ptr(split_str), 1);
		color[i] = temp;
		i++;
	}
	free_double_ptr(split_str);
	return (0);
}

void	set_nums_value(t_p_nums *s_p_nums, char p)
{
	if (p == 'N')
		s_p_nums->np += 1;
	if (p == 'S')
		s_p_nums->sp += 1;
	if (p == 'w')
		s_p_nums->wp += 1;
	if (p == 'e')
		s_p_nums->ep += 1;
}

bool	player_numbers(t_p_nums *n)
{
	if (n->np == 1 && n->sp == 0 && n->wp == 0 && n->ep == 0)
		return (true);
	else if (n->np == 0 && n->sp == 1 && n->wp == 0 && n->ep == 0)
		return (true);
	else if (n->np == 0 && n->sp == 0 && n->wp == 1 && n->ep == 0)
		return (true);
	else if (n->np == 0 && n->sp == 0 && n->wp == 0 && n->ep == 1)
		return (true);
	else
		return (false);
}

bool	check_player_numbers(char **map)
{
	int			i;
	int			j;
	t_p_nums	p_nums;

	i = 0;
	ft_bzero(&p_nums, sizeof(t_p_nums));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr(PLAYER, map[i][j]))
				set_nums_value(&p_nums, map[i][j]);
			j++;
		}
		i++;
	}
	if (player_numbers(&p_nums) == false)
		return (false);
	return (true);
}
