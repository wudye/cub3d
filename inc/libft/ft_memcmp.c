/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:39:40 by mwu               #+#    #+#             */
/*   Updated: 2023/09/13 12:50:36 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		res;
	size_t	i;
	char	*ss1;
	char	*ss2;

	ss1 = (char *)s1;
	ss2 = (char *)s2;
	res = 0;
	i = 0;
	while (i < n && s1 && s2)
	{
		res = (unsigned char)ss1[i] - (unsigned char)ss2[i];
		if (res != 0)
			return (res);
		i++;
	}
	if (i < n)
	{
		res = (unsigned char)ss1[i] - (unsigned char)ss2[i];
		return (res);
	}
	return (0);
}
