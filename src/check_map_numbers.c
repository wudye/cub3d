/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:11:02 by mwu               #+#    #+#             */
/*   Updated: 2024/04/25 16:11:29 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
