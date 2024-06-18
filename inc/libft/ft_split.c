/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:22:45 by mwu               #+#    #+#             */
/*   Updated: 2023/09/20 16:58:26 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	anum(char const *s, char c)
{
	int	i;
	int	rn;

	i = 0;
	rn = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			rn++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (rn);
}

static char	*value_give(char *des, int strilen, int wordlen, char *s)
{
	int	i;

	i = 0;
	while (wordlen > 0)
	{
		des[i] = s[strilen - wordlen];
		wordlen--;
		i++;
	}
	des[i] = '\0';
	return (des);
}

static char	**frees(char **sp, int i)
{
	while (i > 0)
	{
		i--;
		free(sp[i]);
	}
	free(sp);
	return (0);
}

static char	**insplit(char **sp, char const *s, char c, int l)
{
	int	splen;
	int	strilen;
	int	wordlen;

	splen = 0;
	strilen = 0;
	while (splen < l)
	{
		wordlen = 0;
		while (s[strilen] && s[strilen] == c)
			strilen++;
		while (s[strilen] && s[strilen] != c)
		{
			strilen++;
			wordlen++;
		}
		sp[splen] = (char *)malloc(sizeof(char) * (wordlen + 1));
		if (!sp[splen])
			return (frees(sp, splen));
		value_give(sp[splen], strilen, wordlen, (char *)s);
		splen++;
	}
	sp[splen] = 0;
	return (sp);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		reslen;

	if (!s)
		return (NULL);
	reslen = anum(s, c);
	res = (char **)malloc(sizeof (char *) * (reslen + 1));
	if (!res)
		return (NULL);
	res = insplit(res, s, c, reslen);
	return (res);
}
/*
#include <stdio.h>
int	main()
{
	char *s = "hello wolrd ";
	char ** res =  ft_split(s, ' ');
	int	i;
	i = 0;
	while (i < 2)
	{
		free(res[i]);
		i++;
	}
	free(res);
}
*/
