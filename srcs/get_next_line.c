/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:04:20 by mwu               #+#    #+#             */
/*   Updated: 2024/04/22 18:43:42 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free(char *keep, char *buffer)
{
	char	*res;

	res = ft_strjoin1(keep, buffer);
	free(keep);
	return (res);
}

char	*left_line(char	*keep)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (keep[i] && keep[i] != '\n')
		i++;
	if (!keep[i])
	{
		free(keep);
		return (NULL);
	}
	res = ft_calloc1((ft_strlen1(keep) - i), sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	i++;
	while (keep[i])
		res[j++] = keep[i++];
	free(keep);
	return (res);
}

char	*out_line(char *keep)
{
	char	*res;
	int		i;

	i = 0;
	if (!keep[i])
		return (NULL);
	while (keep[i] && keep[i] != '\n')
		i++;
	res = ft_calloc1((i + 2), sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (keep[i] && keep[i] != '\n')
	{
		res[i] = keep[i];
		i++;
	}
	if (keep[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	return (res);
}

char	*read_file(int fd, char *keep)
{
	char	*buffer;
	int		frv;

	if (!keep)
		keep = ft_calloc1(1, 1);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	frv = 1;
	while ((ft_strn1(keep) != 1) && frv > 0)
	{
		frv = read(fd, buffer, BUFFER_SIZE);
		if (frv == -1)
		{
			free(buffer);
			free(keep);
			return (NULL);
		}
		buffer[frv] = '\0';
		keep = ft_strjoin_free(keep, buffer);
	}
	free(buffer);
	return (keep);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	keep = read_file(fd, keep);
	if (!keep)
		return (NULL);
	res = out_line(keep);
	keep = left_line(keep);
	return (res);
}

// int	main()
// {
// 	int fd = open("5line.txt", O_RDONLY);
// 	char	*s;

// 	while(1)
// 	{
// 	s = get_next_line(fd);
// 		printf("%s", s);
// 	if (s == NULL)
// 		break;

// 	free(s);
// 	}
// 	return(0);
// }
