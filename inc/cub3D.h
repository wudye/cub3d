/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:45:02 by cthaler           #+#    #+#             */
/*   Updated: 2024/05/23 18:56:43 by mwu              ###   ########.fr       */
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

# define W 119
# define A 97
# define S 115
# define D 100
# define Q 113
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# define PLAYER "NSEW"
# define IMG_W	800
# define IMG_H	600
# define NORTH 'N'
# define SOURTH 'S'
# define WEST 'W'
# define EAST 'E'
# define FOV 60
# define PLAYER_MOVE 0.005
# define PLAYER_ROTATE 2.0

typedef struct s_var	t_var;

typedef struct s_coordinate
{
	double	d_x;
	double	d_y;
}	t_coordinate;

typedef struct s_texture
{
	int		x;
	int		y;
	double	start;
	double	step;
}	t_texture;

typedef struct s_step
{
	int	x;
	int	y;
}	t_step;

typedef struct s_hit
{
	char			hit_side;
	t_coordinate	sideDist;
	double			perpWallDist;
	t_coordinate	deltaDist;
	t_step			ray_map;
	t_step			step;
	double			pre_dist;
	t_coordinate	hit_pos;
}	t_hit;

typedef struct s_draw
{
	int		start;
	int		end;
	double	high;
}	t_draw;

typedef struct s_render
{
	t_coordinate	*rays;
	t_coordinate	left_side_ray;
	t_coordinate	right_side_ray;
	t_hit			*hits;
	t_draw			draw;
	t_step			mouse_xy;
}	t_render;

typedef struct s_player
{
	double			position_x;
	double			position_y;
	t_coordinate	dir;
	char			player_dir;	
}	t_player;

typedef struct s_img
{
	void	*img_ptr;
	void	*img_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_move
{
	int	up_move;
	int	down_move;
	int	left_move;
	int	right_move;
	int	left_rotate;
	int	right_rotate;
}	t_move;

typedef struct s_var
{
	void		*mlx_init_ptr;
	void		*win_init_ptr;
	char		**texture;
	char		**map;
	int			floor[3];
	int			ceil[3];
	int			floor_rgb;
	int			ceiling_rgb;
	int			map_height;
	int			map_width;
	double		camerax;
	double		cameray;
	t_player	player;
	t_img		*img;
	t_img		*north;
	t_img		*sourth;
	t_img		*west;
	t_img		*east;
	t_render	*ren;
	t_move		move;
}	t_var;

int				main(int argc, char **arv);
int				parse_main(t_var *var, char **argv);
int				parse_argv(char *str);
int				double_ft_len(char **str);
int				check_texture(t_var *var, char **texture);
int				check_color_value(char *str, int *color);
int				check_map_numbers(t_var *var, char **map);
int				handle_spaces(char **map, t_var *var);
int				handle_walls(t_var *var, char **map);
int				handle_inner_zero(char **map, t_var *var);
int				get_file_length1(int fd, int len);
void			exchange_helper(char *temp, char **str, int i);
bool			check_map_value(t_var *var, char **map);
void			map_copy_help(char *str, char *str_copy, int maxi);
void			set_value_texture(int fd, char **str, int len, t_var *var);
int				longest_colum(char **map);
int				check_helper(char **map, int len);
int				set_player_value(char **map, t_var *var);
int				render_mlx(t_var *var);
int				change_int_to_rgb(int r, int g, int b);
void			player_rotate(t_var *var, double change);
void			player_left_move(t_var *var);
void			player_right_move(t_var *var);
void			player_up_move(t_var *var);
void			player_down_move(t_var *var);
int				render_loop(t_var *var);
void			set_player_direction(t_var *var);
void			set_camera_value(t_var *var);
void			error_malloc(t_var *var);
void			free_var(t_var *var);
int				err_return_info(char *str, t_var *var);
void			free_double_ptr(char **str);
void			value_in_render(t_var *var);
void			coordinate_x_y(double step, t_coordinate *add, \
				t_coordinate src);
void			vectot_rotate_by_angle(t_coordinate *ray, double angle, \
				t_player player, double fov_rat);
t_hit			dda_main(t_var *var, t_coordinate ray);
int				loop_in_render(t_var *var);
unsigned int	texture_pixel(t_img *tex, t_coordinate tex_range);
void			*pixel_ptr(t_img *img, int x, int y);
int				close_window(t_var *var);
int				esc_exit(int keysmbol, t_var *var);
int				key_pressed(int keysmbol, t_var *var);
int				key_released(int keysmbol, t_var *var);
void			move_player(t_var *var);
void			hit_value_set(t_var *var);
int				bonus_mouse(int x, int y, t_var *var);
#endif
