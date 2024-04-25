/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:35:26 by mwu               #+#    #+#             */
/*   Updated: 2023/09/08 11:37:35 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dptr;
	const char	*sptr;
	size_t		i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dptr = dest;
	sptr = src;
	while (n > 0)
	{
		dptr[i] = *sptr++;
		i++;
		n--;
	}
	return (dest);
}
