/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:02:31 by mwu               #+#    #+#             */
/*   Updated: 2023/11/17 19:03:42 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	if (s[0] == c || s[0] == '\0')
		count = 0;
	else
		count = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

size_t	ft_wordlen(char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

void	ft_freesplit(char **ptr_2d, size_t i)
{
	while (i > 0)
		free(ptr_2d[--i]);
	free(ptr_2d);
}

char	**ft_splitfunction(size_t count, char *s, char c, char **ptr_2d)
{
	char	*ptr_1d;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		ptr_1d = ft_substr((char *) s, 0, ft_wordlen((char *) s, c));
		if (!ptr_1d)
		{
			ft_freesplit(ptr_2d, i);
			return (NULL);
		}
		ptr_2d[i++] = ptr_1d;
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		s += j;
	}
	ptr_2d[i] = NULL;
	return (ptr_2d);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr_2d;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_countwords((char *) s, c);
	ptr_2d = malloc((count + 1) * sizeof(char *));
	if (!ptr_2d)
		return (NULL);
	ptr_2d = ft_splitfunction(count, (char *) s, c, ptr_2d);
	return (ptr_2d);
}
/*
int main (void)
{
	char str[50]="";
	char del=' ';
	char **retp;
	retp = ft_split(str, del);
	if (!retp)
		return (-1);
	int	i = 0;
	while (retp[i])
	{
		free(retp[i]);
		i++;
	}	
	free(retp);
}
*/
