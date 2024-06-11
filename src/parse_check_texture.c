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

int check_comma(char *st)
{
	int i;
	int l;

	l = 0;
	i = 0;
	while(st[i])
	{
		if (st[i] == ',')
			l++;
		i++;
	}
	if (l != 2)
		return (1);
	return (0);
}

static int	ctc(char *st, char *compare, t_var *var, int *color)
{
	char	**str;

	if (check_comma(st) == 1)
		return (err_return_info("Error Color format wrong",var), 1);
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
		return (err_return_info("Error wrong value", var),\
		free_double_ptr(str), error_malloc(var), 1);
	if (check_color_value(str[1], color) == 1)
		return (err_return_info("Error wrong color value 0-255", var), \
						free_double_ptr(str), 1);
	free_double_ptr(str);
	return (0);
}

static int	check_load_texture(char *str, t_var *var, t_img *img)
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

static int	ctd(char *st, char *compare, \
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
/*
static int  check_texture_content(char *str, int i, t_var *var)
{
	if (i == 0)
		return (check_texture_directions(str, "NO",var, var->north));
	if (i == 1)
		return (check_texture_directions(str, "SO", var, var->sourth));
	if (i == 2)
		return (check_texture_directions(str, "WE", var, var->west));
	if (i == 3)
		return (check_texture_directions(str, "EA", var, var->east));
	if (i == 4)
		return (check_texture_color(str, "F", var, var->floor));
	if (i == 5)
		return (check_texture_color(str, "C", var, var->ceil));
	return (err_return_info("Error in texture", var));
}

*/


static int	check_texture_content(char *str, t_var *var)
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

int check_tab(t_var *var, char *str)
{
	int i;
	int l;

	l = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			return (err_return_info("Error has tab",var), 1);
		i++;
	}
	return (0);
}

int help_repeat(t_repeat *rep)
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

int	repeated_ele(t_var *var, char** textture)
{
	char	**temp;
	t_repeat repeat;

	int i;
	i = 0;
	ft_bzero(&repeat, sizeof(t_repeat));
	while (textture[i])
	{
		temp = ft_split(textture[i], 32);
		if (!temp)
			return (error_malloc(var), 1);
		if (ft_strncmp(temp[0], "NO", 3) == 0)
			repeat.no += 1;
		if (ft_strncmp(temp[0], "WE", 3) == 0)
			repeat.we += 1;
		if (ft_strncmp(temp[0], "SO", 3) == 0)
			repeat.so += 1;
		if (ft_strncmp(temp[0], "EA", 3) == 0)
			repeat.ea += 1;
		if (ft_strncmp(temp[0], "F", 2) == 0)
			repeat.f += 1;
		if (ft_strncmp(temp[0], "C", 2) == 0)
			repeat.c += 1;		
		free_double_ptr(temp);
		i++;
	}
	if (help_repeat(&repeat) ==  1)
		return (err_return_info("Error in texture", var), 1);
	return 0;

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
