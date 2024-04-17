/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:41:57 by cthaler           #+#    #+#             */
/*   Updated: 2024/04/17 13:41:59 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	check_mapname(char *s)
{
	int	len;

	len = ft_strlen(s) - 4;
	if (len <= 0)
		return (1);
	s += len;
	if (!ft_strncmp(s, ".cub", 5))
		return (0);
	return (1);
}

int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	is_mapchar(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || is_whitespace(c))
		return (1);
	return (0);
}
/*
int	check_empty_line(char *s)
{
	int	i;
	int	in_map;

	i = 0;
	in_map = 1;
	while (*s)
	{
		if (
		
		if (*s == '\n' && in_map == 1)
			break ;
		else if (*s == '\n')
			in_map = 0;
		else if (is_mapchar(*s) && in_map != 2)
			in_map = 1;
		else if (*s != '\n')
			in_map = 2;
		s++;
	}
	while (*s)
	{
		if (is_whitespace(*s) || *s == '\n')
			s++;
		else
			return (printf("%s\n", s), 1);
	}
	return (0);
}
*/
int	init_map(char **argv)
{
	int		fd;
	char	*s;
	char	**map;

	//TODO: 
	//	tabs: 8 spaces
	//	check for newline within map
	//	save only map in array
	if (check_mapname(argv[1]))
		return (1);
	fd = open(argv[1], 0);
	if (fd == -1)
		return (1);
	s = read_mapfile(fd, 1);
	if (!s)
		return (close(fd), 1);
	//if (check_empty_line(s))
	//	return (free(s), 1);
	map = ft_split(s, '\n');
	free(s);
	if (!map)
		return (1);
	//********TESTING********
	while (map[i])
		printf("%s\n", map[i++]);
	//***********************
	return (close(fd), 0);
}
