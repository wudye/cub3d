/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:18:14 by mwu               #+#    #+#             */
/*   Updated: 2024/06/13 14:18:17 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	get_file_length_help(int fd, int *i)
{
	char	*temp;
	char	*temp1;

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
		if (check_tab_first(temp1) == true)
		{
			free(temp1);
			continue ;
		}
		(*i)++;
		free(temp1);
	}
}

int	check_helper(char **map, int len)
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

void	length1_help_help(int *i, int *j, int len)
{
	(*i)++;
	if (*i >= 6)
		*i = 6;
	if (*i == 6 && *i <= len)
		(*j)++;
}

bool	check_tabs(char *filename, t_var *var)
{
	char	*temp1;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (err_return_info("Error can not open the map", var));
	while (1)
	{
		temp1 = get_next_line(fd);
		if (temp1 == NULL)
			break ;
		if (check_tab_first(temp1))
			return (free(temp1), err_return_info("Error has tap", var), false);
		free(temp1);
	}
	close (fd);
	return (true);
}
