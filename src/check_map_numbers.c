/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:11:02 by mwu               #+#    #+#             */
/*   Updated: 2024/04/26 12:24:27 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
/*
    seconde way
static void equal_value_set(int j, char *mapi, int maxi)
{
    int valid_len;

    valid_len = 0;
    j = 0;
    while (mapi[j])
    {
        if (mapi[j] == '1' || mapi[j] == '0' || ft_strchr(PLAYER, mapi[j]))
            valid_len++;
        j++;  
    }
    if (valid_len == j)
        return ;
    else
    {
        j = 0;
        while (mapi[j] && (mapi[j] == '\t' || mapi[j] == ' '))
        {
            mapi[j] = '1';
            j++;
        }
        while (valid_len < maxi)
        {
            mapi[valid_len] = '1';
            valid_len++;
        }
    }
}

static void no_equal_set(int maxi, char *mapi, char *temp)
{
    int l;

    l = 0;
    while (mapi[l])
    {
        temp[l] = mapi[l];
        l++;
    }
    while (l < maxi)
    {
        temp[l] = ' ';
        l++;
    }
    temp[l] = '\0';
    equal_value_set(l, temp, maxi);
}


static void	new_map(char **map, int maxi, t_var *var)
{
	int	i;
	int	len;
    char    *temp;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len == maxi)
            equal_value_set(len, map[i], maxi);
        else
        {
            temp = malloc(sizeof(char) * (maxi + 1));
            if (!temp)
                error_malloc(var);
            no_equal_set(maxi, map[i], temp);
            free(map[i]);
            map[i] = temp;
        }
        i++;
	}
}

static int	check_helper(char **map, int len)
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



// map parse about spaces
// if the beginning and end are spaces(only space and tab)
// replace it by 1
// others stay

int	check_map_numbers(t_var *var, char **map)
{

	int		len;
    int     maxi;
    
    if (check_map_value(var, map) == false)
        return (1);
    len = double_ft_len(map);
	maxi = check_helper(map, len);
	new_map(map,  maxi, var);
	if (handle_spaces(map, var) == 1)
		return (1);
	if (handle_walls(var, map) == 1)
		return ( 1);
	if (handle_inner_zero(map, var) == 1)
		return (1);
	return (0);
}
*/
static int	check_helper(char **map, int len)
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

static void	set_map_copy(char **map, char **map_copy, int maxi, t_var *var)
{
	int	len;
	int	i;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		map_copy[i] = malloc(sizeof(char) * (maxi + 1));
		if (!map_copy[i])
			error_malloc(var);
		map_copy_help(map[i], map_copy[i], maxi);
		i++;
	}
	map_copy[i] = 0;
}

static void	change_map_begin(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '1' && map[i][j] != '0' \
						&& !ft_strchr(PLAYER, map[i][j]))
		{
			map[i][j] = '1';
			j++;
		}
		i++;
	}
}
/*
static void	set_map_last(t_var *var, char **map, char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == '2')
				map_copy[i][j] = '1';
			j++;
		}
		i++;
	}
	free_double_ptr(map);
	var->map = map_copy;
}
*/
static char **reset_map_value(char **map, t_var *var, int len)
{
    int i;
    char **map_help;

    i = 0;
    map_help = malloc(sizeof(char *) * (len + 1));
    if (!map_help)
        error_malloc(var);
    while (map[i])
    {
        map_help[i] = ft_strtrim(map[i], "\n");
        if (!map_help[i])
        {
            free_double_ptr(map_help);
            error_malloc(var);
        }
        i++;
    }
    map_help[i] = 0;
    return (map_help);
}

static float	angle(char c)
{
	if (c == 'N')
		return (90);
	else if (c == 'S')
		return (270);
	else if (c == 'E')
		return (180);
	else if (c == 'W')
		return (0);
	return (0);
}

static int	set_player_value(char **map, t_var *var)
{
    int i;
	int	j;
    int num;

    num = 0;
    i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr(PLAYER, map[i][j]))
			{
				var->player_x = i;
				var->player_y = j;
                var->direction = map[i][j];
				var->angle = angle(map[i][j]);
				num += 1;
			}
			j++;
		}
		i++;
	}
	if (num != 1)
		return (1);
	return (0);
}

int	check_map_numbers(t_var *var, char **map)
{
	int		len;
	int		maxi;
	char	**map_copy;
    char    **map_help;

	len = double_ft_len(map);
    map_help = reset_map_value(map, var, len);
	if (check_map_value(var, map_help) == false)
		return (1);
	map_copy = malloc(sizeof(char *) * (len + 1));
	if (!map_copy)
		error_malloc(var);
	change_map_begin(map_help);
	maxi = check_helper(map_help, len);
	set_map_copy(map_help, map_copy, maxi, var);
	if (handle_spaces(map_copy, var) == 1)
		return (free_double_ptr(map_copy), free_double_ptr(map_help), 1);
	if (handle_inner_zero(map_copy, var) == 1)
		return (free_double_ptr(map_copy), free_double_ptr(map_help), 1);
	if (handle_walls(var, map_help) == 1)
		return (free_double_ptr(map_copy), free_double_ptr(map_help), 1);
    if (set_player_value(map, var) == 1)
		return (free_double_ptr(map_copy), free_double_ptr(map_help), err_return_info("Erorr player fail", var), 1);
    free_double_ptr(map_copy);
    free_double_ptr(map_help);
	return (0);
}

/* this is original
int	check_map_numbers(t_var *var, char **map)
{
	int		len;
	int		maxi;
	char	**map_copy;

	if (check_map_value(var, map) == false)
		return (1);
	len = double_ft_len(map);
	map_copy = malloc(sizeof(char *) * (len + 1));
	if (!map_copy)
		error_malloc(var);
	change_map_begin(map);
	maxi = check_helper(map, len);
	set_map_copy(map, map_copy, maxi, var);
	if (handle_spaces(map_copy, var) == 1)
		return (free_double_ptr(map_copy), 1);
	if (handle_inner_zero(map_copy, var) == 1)
		return (free_double_ptr(map_copy), 1);
	if (handle_walls(var, map) == 1)
		return (free_double_ptr(map_copy), 1);
	set_map_last(var, map, map_copy);
	return (0);
}
*/