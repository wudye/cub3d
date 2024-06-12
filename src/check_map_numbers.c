/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:11:02 by mwu               #+#    #+#             */
/*   Updated: 2024/05/23 17:25:33 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

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



// static char	**reset_map_value(char **map, t_var *var, int len)
// {
// 	int		i;
// 	char	**map_help;

// 	i = 0;
// 	map_help = malloc(sizeof(char *) * (len + 1));
// 	if (!map_help)
// 		error_malloc(var);
// 	while (map[i])
// 	{
// 		map_help[i] = ft_strdup(map[i]);
// 		if (!map_help[i])
// 		{
// 			free_double_ptr(map_help);
// 			error_malloc(var);
// 		}
// 		i++;
// 	}
// 	map_help[i] = 0;
// 	return (map_help);
// }
void dfs(char **map, int i, int j, char target)
{
	int max_row;
	int len;

	len = double_ft_len(map) - 1;
	max_row = ft_strlen(map[0]) - 1;

	if (i >= 0 && i <= len && j >= 0 && j <= max_row && map[i][j] == ' ')
	{			
		map[i][j] = '2';

		if (i + 1 >= 0 && i +1 <= len && j >= 0 && j <= max_row )
			dfs(map, i + 1, j, target);
		if (i - 1 >= 0 && i -1 <= len && j >= 0 && j <= max_row )
			dfs(map, i - 1, j, target);
		if (i >= 0 && i <= len && j + 1 >= 0 && j +1 <= max_row )
			dfs(map, i, j + 1, target);
		if (i >= 0 && i <= len && j - 1 >= 0 && j - 1 <= max_row )
			dfs(map, i, j - 1, target);	
	}
}
// bool dfs(char **map, int i, int j, char target)
// {
// 	int max_row;
// 	int len;

// 	len = double_ft_len(map) - 1;
// 	max_row = ft_strlen(map[0]) - 1;

// 	// printf("start %d %d %d %d %c\n",i, j,  max_row, len,  map[i][j]);
// 	if (i < 0 || i > len || j < 0 || j > max_row || map[i][j] == '1')
// 		return (true);
// 	else if (map[i][j] == '0' || ft_strchr(PLAYER, map[i][j]) != NULL)
// 			return (false);
// 	else if (map[i][j] == ' ')
// {	
// 		// printf("%d %d\n", i + 1, len);
// 		map[i][j] = '2';
// 		if (i + 1 >= 0 && i + 1 <= len)
// 			return (dfs(map, i + 1, j, target));
// 		if   (i - 1 >= 0 && i - 1 <= len)
// 			return (dfs(map, i - 1, j, target));
// 		if (j + 1 >= 0 && j + 1 <= max_row)
// 			return (dfs(map, i , j + 1, target));
// 		if  (j - 1 >= 0 && j - 1<= max_row)	
// 			return (dfs(map, i, j - 1, target));

// }
// 	return (true);

// }
void put_wall_two(char **map)
{
	int max_row;
	int len;

	len = double_ft_len(map) - 1;
	max_row = ft_strlen(map[0]) - 1;
	int j;
	// j = 0;
	// 		if (dfs(map,0, 0, '1') == false)
	// 			return (false);

		j = 0;
		while (j <= max_row)
		{
			if (map[0][j] == ' ')
				dfs(map, 0, j, '1');
			if (map[len][j] == ' ')
				dfs(map, len, j, '1');
			j++;
		}
		j = 0;
		while (j <= len)
		{
			if (map[j][0] == ' ')
				dfs(map, j, 0, '1');	
			if (map[j][max_row] == ' ')
				dfs(map, j, max_row, '1');
			j++;
		}
	
	int i = 0;
	while (map[i])
	{
		printf("right>%s<\n", map[i]);
		i++;
	}	
	
	
	

}

bool check_four_walls_help(int line, char **map, int flag)
{
	int len;
	char *temp;
	int i;

	i = 0;
	temp = ft_strtrim(map[line], " ");
	len = ft_strlen(temp) - 1;
	if (flag == 1)
	{
		// printf("%c %c\n", temp[len], temp[line] );
		if (temp[len] != '1' || temp[line] != '1')
			return (free(temp), false);
	}
	if (flag == 0)
	{
		while (temp[i])
		{
			if (temp[i] != '1' && temp[i] != ' ')
				return (free(temp), false);
			i++;
		}
	}
	free(temp);
	return (true);

}
bool check_four_walls(char **map)
{
	int len;
	int i;

	len = double_ft_len(map) - 1;
	if (!check_four_walls_help(0, map, 0) || !check_four_walls_help(len, map, 0))
		return (false);
	i = 1;
	while (i <= len - 1)
	{
		if (!check_four_walls_help(len, map, 1))
			return (false);
		i++;
	} 
	return (true);

}

bool check_space_surround(int i, int j, char **map)
{
	int max_row;
	int len;

	len = double_ft_len(map) - 1;
	max_row = ft_strlen(map[0]) - 1;
	if (map[i][j] == '2')
		return (false);
	else if (map[i][j] == '0' || ft_strchr(PLAYER, map[i][j]))
	{
		if (i + 1 >= 0 && i +1 <= len && j >= 0 && j <= max_row)
			return check_space_surround(i + 1, j, map);
		if (i - 1 >= 0 && i - 1 <= len && j >= 0 && j <= max_row)
			return check_space_surround(i - 1, j, map);
		if (i >= 0 && i <= len && j + 1 >= 0 && j + 1 <= max_row)
			return check_space_surround(i, j + 1, map);
		if (i >= 0 && i <= len && j - 1 >= 0 && j - 1 <= max_row)
			return check_space_surround(i, j - 1, map);
	}
	return (true);
}

bool player_flood_fill(int i, int j, char **map)
{
		int max_row;
	int len;

	len = double_ft_len(map) - 1;
	max_row = ft_strlen(map[0]) - 1;
	if (map[i][j] == '2')
		return (false);
	else if (map[i][j] == '0')
	{
		if (i + 1 >= 0 && i +1 <= len && j >= 0 && j <= max_row)
			return check_space_surround(i + 1, j, map);
		if (i - 1 >= 0 && i - 1 <= len && j >= 0 && j <= max_row)
			return check_space_surround(i - 1, j, map);
		if (i >= 0 && i <= len && j + 1 >= 0 && j + 1 <= max_row)
			return check_space_surround(i, j + 1, map);
		if (i >= 0 && i <= len && j - 1 >= 0 && j - 1 <= max_row)
			return check_space_surround(i, j - 1, map);
	}
	return (true);
}

bool check_player_surround(char **map)
{
	int i;
	int j;
		int max_row;
	int len;

	len = double_ft_len(map) - 1;
	max_row = ft_strlen(map[0]) - 1;
	i = 1;
	while (i <= len)
	{
		printf("%s\n", map[i]);
		j = 1;
		while (map[i][j])
		{
			if (ft_strchr(PLAYER, map[i][j]))
			{
				if (player_flood_fill(i, j, map) == false)
					return(ft_putstr_fd("Error player surround\n", 2), false);
			}
			j++;
		}
		i++;
	}
	return (true);


}
static int	check_map_helper(char **map_copy, \
				t_var *var, char **map)
{
		int max_row;
	int len;

	len = double_ft_len(map) - 1;
	max_row = ft_strlen(map_copy[0]) - 1;
	// if (handle_spaces(map_copy, var) == 1)
	// 	return (free_double_ptr(map_copy), 1);
	// if (handle_inner_zero(map_copy, var) == 1)
	// 	return (free_double_ptr(map_copy), 1);
	// if (handle_walls(var, map) == 1)
	// 	return (free_double_ptr(map_copy), 1);
	if (check_four_walls(map) == false)
		return (ft_putstr_fd("Error in walls\n", 2), 1);
	put_wall_two(map_copy);

	int i = 1;
	int j;
	while (i < len)
	{
		j = 1;
		while (j < max_row)
		{
			// printf("%c\n", map_copy[i][j]);
			if (map_copy[i][j] == '0' && check_space_surround(i, j, map_copy) == false)
				return (ft_putstr_fd("Error in space\n", 2), 1);
			j++;			
		}
		// printf("<%s> %d %d %d\n", map_copy[i], len, max_row, j);
		i++;
	}

	if (check_player_surround(map_copy) == false)
		return (ft_putstr_fd("Error in player\n", 2), 1);
	
	if (set_player_value(map, var) == 1)
		return (1);
	return (0);
}

int	check_map_numbers(t_var *var, char **map)
{
	int		len;
	int		maxi;
	char	**map_copy;

	len = double_ft_len(map);
	map_copy = malloc(sizeof(char *) * (len + 1));
	if (!map_copy)
		return (error_malloc(var), 1);
	maxi = check_helper(map, len);
	set_map_copy(map, map_copy, maxi, var);
	if (check_map_helper(map_copy, var, map) == 1)
		return (free_double_ptr(map_copy), err_return_info("Erorr map", var), 1);
	free_double_ptr(map_copy);
	return (0);
}
