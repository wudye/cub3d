/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:04:11 by mwu               #+#    #+#             */
/*   Updated: 2024/06/13 14:04:14 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	check_comma(char *st)
{
	int	i;
	int	l;

	l = 0;
	i = 0;
	while (st[i])
	{
		if (st[i] == ',')
			l++;
		i++;
	}
	if (l != 2)
		return (1);
	return (0);
}

int	ctc(char *st, char *compare, t_var *var, int *color)
{
	char	**str;

	if (check_comma(st) == 1)
		return (err_return_info("Error Color format wrong", var), 1);
	str = ft_split(st, ' ');
	if (!str)
		error_malloc(var);
	if (double_ft_len(str) != 2)
	{
		free_double_ptr(str);
		return (err_return_info("Error wrong format", var));
	}
	if (ft_strncmp(str[0], compare, ft_strlen(str[0]) + 1) != 0)
		return (err_return_info("Error wrong color name", var), \
						free_double_ptr(str), 1);
	if (check_color_value(str[1], color) == -1)
		return (err_return_info("Error wrong value", var), \
		free_double_ptr(str), error_malloc(var), 1);
	if (check_color_value(str[1], color) == 1)
		return (err_return_info("Error wrong color value 0-255", var), \
						free_double_ptr(str), 1);
	free_double_ptr(str);
	return (0);
}

int	check_load_texture(char *str, t_var *var, t_img *img)
{
	int	size;

	img->img_ptr = mlx_xpm_file_to_image(var->mlx_init_ptr, str, &size, &size);
	if (!img->img_ptr)
		return (ft_putstr_fd("Error xpm file open failed\n", 2), 1);
	img->img_addr = mlx_get_data_addr(img->img_ptr, \
					&img->bits_per_pixel, &img->size_line, &img->endian);
	if (!img->img_addr)
		return (ft_putstr_fd("Error add xpm file open failed\n", 2), 1);
	return (0);
}

int	ctd(char *st, char *compare, \
t_var *var, t_img *vimg)
{
	char	**str;

	str = ft_split(st, ' ');
	if (!str)
		error_malloc(var);
	if (double_ft_len(str) != 2)
	{
		free_double_ptr(str);
		return (err_return_info("Error wrong texture", var), 1);
	}
	if (ft_strncmp(str[0], compare, ft_strlen(str[0]) + 1) != 0)
		return (err_return_info("Error wrong direction", var), \
						free_double_ptr(str), 1);
	if (check_load_texture(str[1], var, vimg) == 1)
		return (err_return_info("Error wrong texture", var), \
		free_double_ptr(str), 1);
	free_double_ptr(str);
	return (0);
}

int	check_texture_content(char *str, t_var *var)
{
	char	**temp;

	temp = ft_split(str, 32);
	if (!temp)
		return (error_malloc(var), 1);
	if (double_ft_len(temp) != 2)
		return (free_double_ptr(temp), \
						err_return_info("Error texture format wrong", var), 1);
	if (ft_strncmp(temp[0], "NO", 3) == 0)
		return (free_double_ptr(temp), ctd(str, "NO", var, var->north));
	else if (ft_strncmp(temp[0], "SO", 3) == 0)
		return (free_double_ptr(temp), ctd(str, "SO", var, var->sourth));
	else if (ft_strncmp(temp[0], "WE", 3) == 0)
		return (free_double_ptr(temp), ctd(str, "WE", var, var->west));
	else if (ft_strncmp(temp[0], "EA", 3) == 0)
		return (free_double_ptr(temp), ctd(str, "EA", var, var->east));
	else if (ft_strncmp(temp[0], "F", 2) == 0)
		return (free_double_ptr(temp), ctc(str, "F", var, var->floor));
	else if (ft_strncmp(temp[0], "C", 2) == 0)
		return (free_double_ptr(temp), ctc(str, "C", var, var->ceil));
	return (free_double_ptr(temp), err_return_info("Error in texture", var));
}
