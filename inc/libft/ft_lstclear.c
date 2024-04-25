/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:19:58 by mwu               #+#    #+#             */
/*   Updated: 2023/09/19 10:03:57 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tp;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		tp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tp;
	}
}
