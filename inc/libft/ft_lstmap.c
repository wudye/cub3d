/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:06:28 by mwu               #+#    #+#             */
/*   Updated: 2023/09/19 11:10:34 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	deal_null(t_list *resu, t_list *temp, void (*del)(void *))
{
	while (resu)
	{
		temp = resu->next;
		del(resu->content);
		free(resu);
		resu = temp;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tep;
	void	*aa;

	if (lst == NULL || del == NULL)
		return (NULL);
	res = NULL;
	while (lst)
	{
		aa = f(lst->content);
		tep = ft_lstnew(aa);
		if (!tep)
		{
			del(aa);
			deal_null(res, tep, del);
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&res, tep);
		lst = lst->next;
	}
	return (res);
}
