/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:26:49 by mwu               #+#    #+#             */
/*   Updated: 2024/05/23 17:54:17 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	check_tab(t_var *var, char *str)
{
	int	i;
	int	l;

	l = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			return (err_return_info("Error has tab", var), 1);
		i++;
	}
	return (0);
}

int	help_repeat(t_repeat *rep)
{
	if (rep->no != 1)
		return (1);
	if (rep->so != 1)
		return (1);
	if (rep->we != 1)
		return (1);
	if (rep->ea != 1)
		return (1);
	if (rep->c != 1)
		return (1);
	if (rep->f != 1)
		return (1);
	return (0);
}

void	repeated_ele_help(char **temp, t_repeat *repeat)
{
	if (ft_strncmp(temp[0], "NO", 3) == 0)
		repeat->no += 1;
	if (ft_strncmp(temp[0], "WE", 3) == 0)
		repeat->we += 1;
	if (ft_strncmp(temp[0], "SO", 3) == 0)
		repeat->so += 1;
	if (ft_strncmp(temp[0], "EA", 3) == 0)
		repeat->ea += 1;
	if (ft_strncmp(temp[0], "F", 2) == 0)
		repeat->f += 1;
	if (ft_strncmp(temp[0], "C", 2) == 0)
		repeat->c += 1;
}

int	repeated_ele(t_var *var, char **textture)
{
	char		**temp;
	t_repeat	repeat;
	int			i;

	i = 0;
	ft_bzero(&repeat, sizeof(t_repeat));
	while (textture[i])
	{
		temp = ft_split(textture[i], 32);
		if (!temp)
			return (error_malloc(var), 1);
		repeated_ele_help(temp, &repeat);
		free_double_ptr(temp);
		i++;
	}
	if (help_repeat(&repeat) == 1)
		return (err_return_info("Error in texture", var), 1);
	return (0);
}

int	check_texture(t_var *var, char **texture)
{
	int	i;

	i = 0;
	while (texture[i])
	{
		if (check_tab(var, texture[i]) == 1)
			return (1);
		i++;
	}
	if (repeated_ele(var, texture) == 1)
		return (1);
	i = 0;
	while (texture[i])
	{
		if (check_texture_content(texture[i], var) == 1)
			return (1);
		i++;
	}
	return (0);
}
