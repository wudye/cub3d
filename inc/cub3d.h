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

# include "libft/libft.h"
# include <stddef.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

# define PLAYER "NSEW"
# define IMG_W	1200
# define IMG_H	600

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
	float angle;
	
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
	int		key_angle;
	int		key_pos;
	float	angle;
	t_ray	r;
	t_player p;
	t_img1	*img;
	t_img1	*north;
	t_img1	*sourth;
	t_img1	*west;
	t_img1	*east;
}	t_var;

//utils.c
int	arr_len(char **arr);
int	check_bounds(float x, float y, char **map);
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

#endif
