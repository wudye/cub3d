/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:30:19 by mwu               #+#    #+#             */
/*   Updated: 2024/05/23 17:54:55 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	get_file_length(int fd)
{
	int		i;

	i = 0;
	get_file_length_help(fd, &i);
	return (i);
}

static void	set_value_map(int fd, char **str, int len, t_var *var)
{
	char	*temp;
	int		i;
	char	*temp1;

	i = 0;
	while (i < len)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		temp1 = ft_strtrim(temp, " ");
		if (temp1 && (ft_strncmp(temp1, "\n", 2) == 0 \
		|| check_tab_first(temp1)))
		{
			free(temp);
			free(temp1);
			continue ;
		}
		str[i] = ft_strtrim(temp, "\n");
		free(temp);
		free(temp1);
		if (!str[i])
			error_malloc(var);
		i++;
	}
}

static int	set_data_value(int fd, t_var *var, int len)
{
	char	*temp;

	var->texture = malloc(sizeof(char *) * 7);
	if (!var->texture)
		error_malloc(var);
	set_value_texture(fd, var->texture, 6, var);
	if (len - 6 <= 0)
		return (err_return_info("Error no map", var));
	var->map = malloc(sizeof(char *) * (len - 6 + 1));
	if (!var->map)
		error_malloc(var);
	set_value_map(fd, var->map, len - 6, var);
	var->map[len - 6] = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		free(temp);
	}
	return (0);
}

static int	open_map_file(char *filename, t_var *var)
{
	int	fd;
	int	len;
	int	k;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (err_return_info("Error can not open the map", var));
	len = get_file_length(fd);
	if (len == 0)
		return (close(fd), err_return_info("Error empty map", var));
	close (fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (close(fd), err_return_info("Error can not open the map", var));
	k = get_file_length1(fd, len);
	if (k == -1)
		return (close(fd), err_return_info("Error map has empty line", var));
	close (fd);
	fd = open(filename, O_RDONLY);
	if (set_data_value(fd, var, len) == 1)
		return (close(fd), 1);
	return (close(fd), 0);
}

int	parse_main(t_var *var, char **argv)
{
	if (open_map_file(argv[1], var) == 1)
		return (1);
	if (check_texture(var, var->texture) == 1)
		return (1);
	if (check_player_numbers(var->map) == false)
		return (err_return_info("Error player number", var));
	if (check_map_value(var, var->map) == false)
		return (err_return_info("Error map has novalid char", var));
	if (check_map_numbers(var, var->map) == 1)
		return (1);
	return (0);
}
