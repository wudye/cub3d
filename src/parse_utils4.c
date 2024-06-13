/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:24:56 by mwu               #+#    #+#             */
/*   Updated: 2024/06/13 17:24:59 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	length1_help3(int fd, int *i, int *j, int len)
{
	char	*temp;
	char	*temp1;
	int		cp;

	cp = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		temp1 = ft_strtrim(temp, " ");
		free(temp);
		if (temp1 && (ft_strncmp(temp1, "\n", 2) == 0))
		{
			if (*i <= len)
				(*j)--;
			free(temp1);
			continue ;
		}
		cp++;
		(*j)++;
		(*i)++;
		free(temp1);
	}
	(*j) -= cp;
}

void	length1_help2(int fd, int *i)
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
		if (temp1 && (ft_strncmp(temp1, "\n", 2) != 0))
		{
			free(temp1);
			break ;
		}
		free(temp1);
		(*i)++;
	}
}

void	length1_help1(int fd, int *i, int *k)
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
		if (*i >= 6)
		{
			free(temp1);
			break ;
		}
		if (temp1 && (ft_strncmp(temp1, "\n", 2) == 0))
		{
			free(temp1);
			continue ;
		}
		(*i)++;
		(*k)++;
		free(temp1);
	}
}

void	length1_help(int fd, int len, int *i, int *j)
{
	int		k;

	k = 0;
	length1_help1(fd, i, &k);
	length1_help2(fd, i);
	length1_help3(fd, i, j, len);
	(*i) = k;
}
