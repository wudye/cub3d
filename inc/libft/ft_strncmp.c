/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:43:34 by mwu               #+#    #+#             */
/*   Updated: 2023/09/14 16:13:34 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	c1;
	int				c2;

	c1 = 0;
	c2 = 0;
	while (c1 < n && s1[c1])
	{
		c2 = (unsigned char)s1[c1] - (unsigned char)s2[c1];
		if (c2 != 0)
			return (c2);
		c1++;
	}
	if (c1 < n)
		return ((unsigned char)s1[c1] - (unsigned char)s2[c1]);
	return (0);
}
