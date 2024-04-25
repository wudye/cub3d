/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:50:22 by mwu               #+#    #+#             */
/*   Updated: 2023/09/19 10:28:16 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tp;

	tp = *lst;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while (tp->next)
	{
		tp = tp->next;
	}
	tp->next = new;
}
