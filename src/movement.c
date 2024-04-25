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

static void	change_player(t_cube *c, int press)
{
	if (press)
	{
		c->key_press = 1;
		//c->p.angle++;
		//if (c->p.angle == 360)
		//	c->p.angle = 0;
	}
	else
		c->key_press = 0;
}

int	key_press(int key, void *p)
{
	if (key == 0xFF1B)
		exit(0);
	if (key == 'd')
		change_player(p, 1);
	return (0);
}

int	key_release(int key, void *p)
{
	if (key == 'd')
		change_player(p, 0);
	return (0);
}

