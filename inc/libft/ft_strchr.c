/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:20:39 by mwu               #+#    #+#             */
/*   Updated: 2023/09/14 12:20:48 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ps;
	int		j;

	ps = (char *)s;
	j = 0;
	while (ps[j])
	{
		if (ps[j] == (char)c)
			return (ps + j);
		j++;
	}
	if (ps[j] == (char)(c))
		return (ps + j);
	return (NULL);
}
