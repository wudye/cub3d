/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_key_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:56:02 by mwu               #+#    #+#             */
/*   Updated: 2024/05/23 17:59:39 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	close_window(t_var *var)
{
	free_var(var);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

/*
    this is for keyrelease
    mlx_key_hook(var->win_init_ptr, &esc_key, var);
    need this X11/keysym.h 
    "key symbol" and not "key code". That's because 
    a key code is not the same thing than a key symbol.
    The key code for the "A" key on an AZERTY keyboard 
    layout will be the same than the key code for the 
    "Q" key on a QWERTY layout. However, what we want
    to deal with is the symbol. If the key I expect     
    to be pressed is "A", I want it to be "A" whatever 
    the keyboard layout of the user is. I want to get
    it by the symbol. This conversion is done by the
    minilibx (to be exact, Xlib handles it) internally. 
    What we're getting in handle_input is the correct key symbol.
*/

int	key_pressed(int keysmbol, t_var *var)
{
	if (keysmbol == XK_Escape)
		close_window(var);
	if (keysmbol == XK_Left)
		var->move.left_rotate = 1;
	if (keysmbol == XK_Right)
		var->move.right_rotate = 1;
	if (keysmbol == XK_A || keysmbol == XK_a)
		var->move.left_move = 1;
	if (keysmbol == S || keysmbol == DOWN)
		var->move.down_move = 1;
	if (keysmbol == W || keysmbol == UP)
		var->move.up_move = 1;
	if (keysmbol == XK_D || keysmbol == XK_d)
		var->move.right_move = 1;
	return (0);
}

int	key_released(int keysmbol, t_var *var)
{
	if (keysmbol == XK_Left)
		var->move.left_rotate = 0;
	if (keysmbol == XK_Right)
		var->move.right_rotate = 0;
	if (keysmbol == XK_A || keysmbol == XK_a)
		var->move.left_move = 0;
	if (keysmbol == S || keysmbol == DOWN)
		var->move.down_move = 0;
	if (keysmbol == W || keysmbol == UP)
		var->move.up_move = 0;
	if (keysmbol == XK_D || keysmbol == XK_d)
		var->move.right_move = 0;
	return (0);
}
