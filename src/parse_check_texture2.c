/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:44:17 by cthaler           #+#    #+#             */
/*   Updated: 2024/05/30 21:44:20 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	arr_to_str2(char *s, char **str)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			s[k++] = str[i][j++];
		i++;
	}
	s[k] = 0;
}

static char	*arr_to_str(char *st, t_var *var)
{
	char	**str;
	char	*st2;
	int		len;
	int		i;

	str = ft_split(st, ' ');
	i = 1;
	len = 0;
	if (!str)
		error_malloc(var);
	while (str[i])
		len += ft_strlen(str[i++]);
	st2 = malloc(len + 1);
	if (!st2)
	{
		free_double_ptr(str);
		error_malloc(var);
	}
	arr_to_str2(st2, str);
	return (free_double_ptr(str), st2);
}

char	*ctc2(char *st, t_var *var)
{
	char	*st2;
	int		i;
	int		commas;

	i = 0;
	commas = 0;
	st2 = arr_to_str(st, var);
	while (st2[i])
	{
		if (!ft_isdigit(st2[i]) && st2[i] != ',')
			return (free(st2), NULL);
		else if (st2[i] == ',' && !ft_isdigit(st2[i + 1]))
			return (free(st2), NULL);
		if (st2[i] == ',')
			commas++;
		i++;
	}
	if (commas != 2)
		return (free(st2), NULL);
	return (st2);
}

int	count_nrs(char *s)
{
	int	nrs;

	nrs = 0;
	while (*s)
	{
		if (ft_isdigit(*s))
		{
			nrs++;
			while (ft_isdigit(*s))
				s++;
		}
		while (*s && !ft_isdigit(*s))
			s++;
	}
	return (nrs);
}
