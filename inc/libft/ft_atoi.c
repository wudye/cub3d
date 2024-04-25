/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:43:48 by mwu               #+#    #+#             */
/*   Updated: 2023/09/20 09:14:00 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	posi_neg(const char *s, int c)
{
	if (s[c] == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sig;
	int	i;

	i = 0;
	while (nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v'
		|| nptr[i] == '\n' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	sig = posi_neg(nptr, i);
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	res = 0;
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	res *= sig;
	return (res);
}
/*
int	main()
{
	printf("%d\n", atoi("-0"));
	printf("%d\n", ft_atoi("-0")); 
}
*/
