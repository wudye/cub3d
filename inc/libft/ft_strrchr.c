/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:53:14 by mwu               #+#    #+#             */
/*   Updated: 2023/09/14 11:35:04 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ps;
	int		i;

	ps = (char *)s;
	i = 0;
	while (ps[i])
		i++;
	while (i >= 0)
	{
		if (ps[i] == (char) c)
			return ((ps + i));
		i--;
	}
	return (NULL);
}