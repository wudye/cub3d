/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:44:08 by cthaler           #+#    #+#             */
/*   Updated: 2024/04/17 13:44:09 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	err(char *s)
{
	while (*s)
		write (2, s++, 1);
	return (1);
}

int	main(int argc, char **argv)
{
(void)argv;
	if (argc != 2)
		return (err("Error: invalid nr of args\n"));
	//Test calc_ray function, delete later
	//****************************************
	t_img img;
	t_var	cube;
	
	void *mlx_ptr = mlx_init();
	void *win_ptr = mlx_new_window(mlx_ptr, IMG_W, IMG_H, "cub3d");
	
	char **map = malloc(sizeof(map) * 11);
	int i = 0;
	int j = 0;
	while (i < 10)
	{
		j = 0;
		map[i] = malloc(11);
		while (j < 10)
		{
			char c = '0';
			if (!i || i == 9 || !j || j == 9)
				c = '1';
			map[i][j] = c;
			j++;
		}
		map[i][j] = 0;
		i++;
	}
	map[i] = 0;
	
	//init img struct*****************************************
	//img.floor_rgb = create_trgb(0, 0, 0, 0);
	//img.ceiling_rgb = create_trgb(0, 255, 255, 255);
	//img.ptr = mlx_new_image(mlx_ptr, IMG_W, IMG_H);
	//img.addr = (int *)mlx_get_data_addr(img.ptr, &img.bitsinpixel,
	//			&img.line_bytes, &img.endian);
	//********************************************************
	
	//change map test***************
	map[5][5] = '1';
	map[5][6] = '1';
	map[4][5] = '1';
	map[4][6] = '1';
	//******************************
	
	cube.img = &img;
	cube.win_ptr = win_ptr;
	cube.mlx_ptr = mlx_ptr;
	cube.floor_rgb = create_trgb(0, 0, 0, 0);
	cube.ceiling_rgb = create_trgb(0, 255, 255, 255);
	cube.map = map;
	cube.key_press = 0;
	
	cube.p.x = 7;
	cube.p.y = 7;
	cube.p.angle = 45;
	
	//for testing: print map
	
	i = 0;
	j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			printf("%c ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	mlx_hook(cube.win_ptr, 17, 0, close_window, &cube);
	//mlx_key_hook(cube.win_ptr, key_handler, &cube);
	
	mlx_hook(win_ptr, 2, 1L << 0, key_press, &cube);
	//mlx_hook(win_ptr, 2, 1L << 1, key_release, &cube);
	
	//render_frame(&cube);
	mlx_loop_hook(cube.mlx_ptr, render_frame, &cube);
	mlx_loop(mlx_ptr);
	
	//****************************************
	return (0);
}
