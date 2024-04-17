/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:19:06 by mwu               #+#    #+#             */
/*   Updated: 2023/09/20 09:37:00 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_exitchar(char src, char const *check)
{
	int	i;

	i = 0;
	while (check[i])
	{
		if (check[i] == src)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;
	int		i;

	start = 0;
	i = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_exitchar(s1[start], set))
		start++;
	while (end > start && ft_exitchar(s1[end - 1], set))
		end--;
	res = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	while (start < end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}
