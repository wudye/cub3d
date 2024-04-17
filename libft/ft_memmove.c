/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:27:28 by mwu               #+#    #+#             */
/*   Updated: 2023/09/14 15:29:06 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*mdest;
	unsigned char	*msrc;

	mdest = (unsigned char *)dest;
	msrc = (unsigned char *)src;
	if (mdest > msrc && mdest < msrc + n)
	{
		while (n-- > 0)
		{
			mdest[n] = msrc[n];
		}
	}
	else
	{
		ft_memcpy(mdest, msrc, n);
	}
	return (dest);
}
