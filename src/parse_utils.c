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
	char **str1;
	char *str2;
	int len;

	str1 = ft_split(str, '/');
	len = double_ft_len(str1);
	str2 = str1[len - 1];
	n = ft_strlen(str2);
	if (n == 4)
		return (free_double_ptr(str1), ft_putstr_fd("Error need full file name\n", 2), 1);
	str2 += (n - 4);
	if (ft_strncmp(str2, ".cub", 5) == 0)
		return (free_double_ptr(str1), 0);
	free_double_ptr(str1);
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

bool check_tab_first(char *temp1)
{
	int i;
	int len;

	len = ft_strlen(temp1);
	i = 0;
	while (i < len - 1)
	{
		if (temp1[i] != 9)
			return (false);
		i++;
	}
	return (true);
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
		if (temp1 && (ft_strncmp(temp1, "\n", 2) == 0 || check_tab_first(temp1)))
		{
			free(temp1);
			continue;
		}
		(*i)++;
		if (*i > 5 && *i < len)
			(*j)++;
		free(temp1);
	}
}

int	get_file_length1(int fd, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	length1_help(fd, len, &i, &j);
	if (i - 6 <= 0)
		return (-1);
	if (j < 0)
		return (-1);
	return (i);
}
