/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:48:08 by mwu               #+#    #+#             */
/*   Updated: 2024/04/22 14:52:11 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

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

int	parse_argv(char *str)
{
	int	n;

	n = ft_strlen(str);
	if (n == 4)
		return (ft_putstr_fd("Error need full file name\n", 2), 1);
	str += (n - 4);
	if (ft_strncmp(str, ".cub", 5) == 0)
		return (0);
	return (1);
}

int	double_ft_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	length1_help(int fd, int len, int *i, int *j)
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
		temp = ft_strtrim(temp1, "\t");
		free(temp1);
		if (temp && ft_strncmp(temp, "\n", 2) == 0)
		{
			free(temp);
			if (*i > 6 && *i < len)
				(*j)++;
			continue ;
		}
		(*i)++;
		free(temp);
	}
}

int	get_file_length1(int fd, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	length1_help(fd, len, &i, &j);
	if (i - 6 == 0)
		return (-1);
	if (j > 0)
		return (-1);
	return (i);
}
