/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:18:50 by mwu               #+#    #+#             */
/*   Updated: 2023/10/03 17:22:18 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

void	*ft_bzero1(void *s, unsigned int n)
{
	unsigned char	*p;

	p = s;
	while (n--)
	{
		*p = '\0';
		p++;
	}
	return (p);
}

void	*ft_calloc1(unsigned int n1, unsigned int n2)
{
	void			*res;

	res = malloc(n1 * n2);
	if (!res)
		return (NULL);
	ft_bzero1(res, n1 * n2);
	return (res);
}

int	ft_strn1(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

int	ft_strlen1(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc((ft_strlen1(s1) + ft_strlen1(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}
