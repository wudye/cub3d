/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:38:51 by mwu               #+#    #+#             */
/*   Updated: 2023/09/13 18:13:39 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(s);
	res = (char *)malloc(sizeof(char) *(i + 1));
	if (!res)
		return (NULL);
	while (j < i)
	{
		res[j] = s[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}
