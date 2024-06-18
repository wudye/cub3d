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

int	get_file_length_help(int fd, int *i)
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
			return (ft_putstr_fd("Error in strim\n", 2), 1);
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
	return (0);
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

bool	check_tabs_help(int fd, t_var *var)
{
	char	*temp1;

	while (1)
	{
		temp1 = get_next_line(fd);
		if (temp1 == NULL)
			break ;
		if (check_tab_first(temp1))
		{
			free(temp1);
			while (1)
			{
				temp1 = get_next_line(fd);
				if (temp1 == NULL)
					break ;
				free(temp1);
			}
			return (err_return_info("Error has tap", var), false);
		}
		free(temp1);
	}
	if (close(fd) == -1)
		return (err_return_info("Error close", var), false);
	return (true);
}

bool	check_tabs(char *filename, t_var *var)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (err_return_info("Error can not open the map", var), false);
	return (check_tabs_help(fd, var));
}
