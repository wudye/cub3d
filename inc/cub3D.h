/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:34:10 by mwu               #+#    #+#             */
/*   Updated: 2024/04/26 12:23:19 by mwu              ###   ########.fr       */
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


# include "libft/libft.h"
# include "get_next_line.h"
#include "my_try.h"


# define PLAYER "NSEW"
# define IMG_W	1200
# define IMG_H	600
/*


//change name later
typedef struct	s_img1
{
	void	*ptr;
	int	*addr;
	int	bitsinpixel;
	int	line_bytes;
	int	endian;
	int	floor_rgb;
	int	ceiling_rgb;
	//int	player_rgb;
	//int	map[64];
	//t_player	p;
	//t_ray		ray;
}		t_img1;

typedef struct	s_cube
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img1	*img;
	t_player	p;
	t_ray	r;
	char	**map;
	int	floor_rgb;
	int	ceiling_rgb;
	int	key_press;
}		t_cube;
*/

typedef struct	s_ray
{
	float x;
	float y;
	float dist;
	float angle;
	
}		t_ray;

typedef struct	s_player
{
	float x;
	float y;
	int angle;
	
}		t_player;


typedef struct s_img
{
	void	*img_ptr;
	int	*img_addr;
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
	int		player_x;
	int		player_y;
	int		key_press;
    char    direction;
	float	angle;
	t_ray	r;
	t_player p;
	t_img	*img;
	t_img	*north;
	t_img	*sourth;
	t_img	*west;
	t_img	*east;
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
// free functions
void	error_malloc(t_var *var);
void	free_var(t_var *var);
int		err_return_info(char *str, t_var *var);
void	free_double_ptr(char **str);


//utils.c
int	arr_len(char **arr);
int	check_bounds(int x, int y, char **map);
//math.c
float	rad(float degree);
//init_rays.c
void	calc_ray(t_player *p, t_ray *r, float angle, char **map);
//init_rays2.c
int	check_hor_map(t_ray *r, char **map);
int	check_vert_map(t_ray *r, float x, float y, char **map);
//render_utils.c
int	create_trgb(int t, int r, int g, int b);
//render.c
int	render_frame(t_var *c);
//movement.c
int	key_press(int key, void *p);
 int	key_release(int key, void *p);
 int	close_window(t_var *var);

 // my try 
int mouse_hook(int x, int y, t_var *var, t_camera *camera);
 void init_camera(t_var *var, t_camera *camera);
int	window_loop(t_var *this, t_camera *camera);

#endif
