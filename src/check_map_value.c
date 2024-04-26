/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:35:35 by mwu               #+#    #+#             */
/*   Updated: 2024/04/26 13:13:12 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	texture_help(t_var *var, char *st, char *temp1, int *i)
{
	free(temp1);
	if (!st)
		error_malloc(var);
	(*i)++;
}

void	set_value_texture(int fd, char **str, int len, t_var *var)
{
	char	*temp;
	int		i;
	char	*temp1;

	i = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		temp1 = ft_strtrim(temp, " ");
		free(temp);
		if (temp1 && ft_strncmp(temp1, "\n", 2) == 0)
		{
			free(temp1);
			continue ;
		}
		str[i] = ft_strtrim(temp1, "\n");
		texture_help(var, str[i], temp1, &i);
		if (i == len)
			break ;
	}
	str[i] = 0;
}

bool	check_map_value(t_var *var, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' \
							&& map[i][j] != ' ' && map[i][j] != '\t' \
							&& ft_strchr(PLAYER, map[i][j]) == NULL)
			{
				err_return_info("Error map has novalid char", var);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

void	map_copy_help(char *str, char *str_copy, int maxi)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str_copy[i] = str[i];
		i++;
	}
	while (i < maxi)
	{
		str_copy[i] = '2';
		i++;
	}
	str_copy[i] = '\0';
}
