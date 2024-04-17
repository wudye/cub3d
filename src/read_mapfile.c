/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mapfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:24:17 by cthaler           #+#    #+#             */
/*   Updated: 2023/11/16 11:24:19 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static char	*join_strings(char *s1, char *s2)
{
	char	*dest;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (free(s1), NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	free(s1);
	return (dest);
}

char	*read_mapfile(int fd, int i_read)
{
	char	*buf;
	char	*line;

	buf = ft_calloc(1, 2);
	if (!buf)
		return (NULL);
	line = ft_calloc(1, 1);
	if (!line)
		return (free(buf), NULL);
	while (fd > 2)
	{
		i_read = read(fd, buf, 1);
		if (!buf[0])
			break ;
		if (i_read < 0)
			return (free(buf), free(line), NULL);
		buf[i_read] = 0;
		line = join_strings(line, buf);
		if (!line)
			return (free(buf), NULL);
	}
	if (!line[0])
		return (free(line), free(buf), NULL);
	return (free(buf), line);
}
/*
	#include<stdio.h>
#include <fcntl.h>
int main()
{
	int	fd;
	char	*s;

	fd = open("maps/map01.ber", 0);
	if (fd <= 0)
		return (0);
	s = read_mapfile(fd, 1);
	free(s);
	close(fd);
	return 0;
}
*/
