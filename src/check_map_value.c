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

#include "../inc/cub3D.h"

static void	texture_help(t_var *var, char *st, int *i)
{
	if (!st)
		error_malloc(var);
	(*i)++;
}

char	*reduce_help3(char *temp, int fd)
{
	char	*temp1;
	char	*te;

	temp1 = ft_strtrim(temp, "\n");
	free(temp);
	if (!temp1)
	{
		while (1)
		{
			te = get_next_line(fd);
			if (te == NULL)
				break ;
			free(te);
		}
		return (NULL);
	}
	return (temp1);
}

void	set_value_texture(int fd, int i, int len, t_var *var)
{
	char	*temp;
	char	*temp1;

	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		temp1 = reduce_help(temp, fd);
		if (!temp1)
			error_malloc(var);
		if (temp1 && (ft_strncmp(temp1, "\n", 2) == 0))
		{
			free(temp1);
			continue ;
		}
		var->texture[i] = reduce_help3(temp1, fd);
		if (!var->texture[i])
			error_malloc(var);
		texture_help(var, var->texture[i], &i);
		if (i == len)
			break ;
	}
	var->texture[i] = 0;
}

bool	check_map_value(t_var *var, char **map)
{
	int	i;
	int	j;

	(void) var;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' \
							&& map[i][j] != ' ' \
							&& ft_strchr(PLAYER, map[i][j]) == NULL)
				return (false);
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
		str_copy[i] = ' ';
		i++;
	}
	str_copy[i] = '\0';
}
