/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map_file_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:10:45 by mwu               #+#    #+#             */
/*   Updated: 2024/06/18 13:10:47 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	open_map_file_first(char *filename, t_var *var)
{
	int	fd;
	int	len;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error can not open the map\n", 2), -1);
	len = get_file_length(fd, var);
	if (len == 0 || len == 6)
	{
		if (close (fd) == -1)
			return (ft_putstr_fd("Error empty map\n", 2), -1);
		return (ft_putstr_fd("Error empty map\n", 2), -1);
	}
	if (close (fd) == -1)
		return (ft_putstr_fd("Error empty map\n", 2), -1);
	return (len);
}

int	open_map_file_second(char *filename, int len)
{
	int	fd;
	int	k;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error can not open the map\n", 2), -1);
	k = get_file_length1(fd, len);
	if (k == -1)
	{
		if (close (fd) == -1)
			return (ft_putstr_fd("Error empty map\n", 2), -1);
		return (ft_putstr_fd("Error map has empty line\n", 2), -1);
	}
	if (close (fd) == -1)
		return (ft_putstr_fd("Error empty map\n", 2), -1);
	return (k);
}

int	open_map_file_third(char *filename, t_var *var, int len)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (err_return_info("Error map has empty line", var));
	if (set_data_value(fd, var, len) == 1)
	{
		if (close (fd) == -1)
			return (err_return_info("Error empty map", var));
		return (1);
	}
	if (close (fd) == -1)
		return (err_return_info("Error empty map", var));
	return (0);
}

char	*reduce_help4(char *temp, int fd)
{
	char	*temp1;

	temp1 = ft_strtrim(temp, " ");
	if (!temp1)
	{
		free(temp);
		while (1)
		{
			temp1 = get_next_line(fd);
			if (temp1 == NULL)
				break ;
			free(temp1);
		}
		return (NULL);
	}
	return (temp1);
}

int	set_value_map_help(char *temp, char *temp1)
{
	if (temp1 && (ft_strncmp(temp1, "\n", 2) == 0 \
		|| check_tab_first(temp1)))
	{
		free(temp);
		free(temp1);
		return (1);
	}
	return (0);
}
