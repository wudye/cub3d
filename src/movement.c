/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:36:57 by cthaler           #+#    #+#             */
/*   Updated: 2024/04/25 10:36:59 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	close_window(t_var *var)
{
	free_var(var);
	exit(0);
	return (0);
}

static void	change_angle(t_var *c, int press)
{
	c->key_angle = press;
}

static void	change_pos(t_var *c, int press)
{
	c->key_pos = press;
}

int	key_release(int key, void *p)
{
	if (key == 'a' || key == 'd')
		change_angle(p, 0);
	if (key == 'w' || key == 's')
		change_pos(p, 0);
	return (0);
}

int	key_press(int key, void *p)
{
	if (key == 0xFF1B)
		return (free_var(p), exit(0), 0);
	if (key == 'd')
		change_angle(p, 1);
	if (key == 'a')
		change_angle(p, -1);
	if (key == 'w')
		change_pos(p, 1);
	if (key == 's')
		change_pos(p, -1);
	return (0);
}
