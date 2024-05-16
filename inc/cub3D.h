/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:45:02 by cthaler           #+#    #+#             */
/*   Updated: 2024/04/17 13:45:03 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stddef.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdbool.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <X11/keysym.h>


# include "libft/libft.h"
# include "get_next_line.h"
# include "my_try.h"

# define PLAYER "NSEW"
# define IMG_W	1280
# define IMG_H	920
#define SPEED 0.03f
#define DISTANCE	0.2f

typedef struct	s_player
{
	double position_x;
	double position_y;
    int direction_x;
    int direction_y;
    char    player_dir;
	
}		t_player;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_var
{
	void	*mlx_init_ptr;
	void	*win_init_ptr;
	char	**texture;
	char	**map;
	int		floor[3];
	int		ceil[3];
	int		floor_rgb;
	int		ceiling_rgb;
    int     map_height;
    double    camerax;
    double cameray;
	t_player player;
	t_img	*img;
	t_img	*north;
	t_img	*sourth;
	t_img	*west;
	t_img	*east;
    t_render ren;
}	t_var;


int		main(int argc, char **arv);

// parse part
int		parse_main(t_var *var, char **argv);
int		parse_argv(char *str);
int		double_ft_len(char **str);
int		check_texture(t_var *var, char **texture);
int		check_color_value(char *str, int *color);
int		check_map_numbers(t_var *var, char **map);
int		handle_spaces(char **map, t_var *var);
int		handle_walls(t_var *var, char **map);
int		handle_inner_zero(char **map, t_var *var);
int		get_file_length1(int fd, int len);
void	exchange_helper(char *temp, char **str, int i);
bool    check_map_value(t_var *var, char **map);
void    map_copy_help(char *str, char *str_copy, int maxi);
void	set_value_texture(int fd, char **str, int len, t_var *var);
// render
int		render_mlx(t_var *var);

// render utils
int	change_int_to_rgb(int r, int g, int b);

void player_rotate(t_var *var, int change);
void player_left_move(t_var *var);
void player_right_move(t_var *var);
void player_up_move(t_var *var);
void player_down_move(t_var *var);

int render_loop(t_var *var);
void set_player_direction(t_var *var);
void set_camera_value(t_var *var);



// free functions
void	error_malloc(t_var *var);
void	free_var(t_var *var);
int		err_return_info(char *str, t_var *var);
void	free_double_ptr(char **str);



#endif
