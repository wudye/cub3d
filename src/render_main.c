/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mlx_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:42:34 by mwu               #+#    #+#             */
/*   Updated: 2024/05/02 13:47:46 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
// static void	render_init_var(t_var *var)
// {
// 	var->floor_rgb = change_int_to_rgb(var->floor[0], var->floor[1], var->floor[2]);
// 	var->ceiling_rgb = change_int_to_rgb(var->ceil[0], var->ceil[1], var->ceil[2]);

// }

static int close_window(t_var *var)
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
static int press_key(int keysmbol, t_var *var)
{
    if (keysmbol == XK_Escape)
        close_window(var);
    else if (keysmbol == XK_Left)
        player_rotate(var, -3);
    else if (keysmbol == XK_Right)
        player_rotate(var, 3);
    else if (keysmbol == XK_A || keysmbol == XK_a)
        player_left_move(var);
    else if (keysmbol == XK_S || keysmbol == XK_Down)
        player_down_move(var);
    else if (keysmbol == XK_W || keysmbol == XK_Up)
        player_up_move(var);
    else if (keysmbol == XK_D || keysmbol == XK_d)
        player_right_move(var);
    render_loop(var);
    return (EXIT_SUCCESS);
}

int	render_mlx(t_var *var)
{
   
    var->win_init_ptr = mlx_new_window(var->mlx_init_ptr, IMG_W, IMG_H, "cub3D");
	if (!var->mlx_init_ptr)
		return (error_malloc(var), 1);
    set_player_direction(var);
    set_camera_value(var);
	mlx_mouse_hide(var->mlx_init_ptr, var->win_init_ptr); 
	mlx_hook(var->win_init_ptr, 17, 0, close_window, var);

    mlx_hook(var->win_init_ptr, 2, (1L << 0), press_key, var);
	mlx_loop_hook(var->mlx_init_ptr, render_loop, var);

	mlx_loop(var->mlx_init_ptr);
	return (0);
}
