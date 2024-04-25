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
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

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
	int angle;
	
}		t_player;

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

//utils.c
int	arr_len(char **arr);
int	check_bounds(int x, int y, char **map);
//math.c
float	rad(float degree);
//init_rays.c
void	calc_ray(t_player *p, t_ray *r, float angle, char **map);
//render_utils.c
int	create_trgb(int t, int r, int g, int b);
//render.c
int	render_frame(t_cube *c);
//movement.c
int	key_press(int key, void *p);
int	key_release(int key, void *p);

#endif
