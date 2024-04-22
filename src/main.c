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
	
	t_ray	r;
	t_player	p;
	
	p.x = 8;
	p.y = 8;
	p.angle = 90;
	
	float offset = -50;
	calc_ray(&p, &r, p.angle + offset, map);
	//calc_ray(&p, &r, 31, map);
	
	printf("Angle: %f x_wall: %f y_wall: %f dist: %f\n",
		p.angle + offset, r.x, r.y, r.dist);
	//for testing: print map
	/*
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
	*/
	//****************************************
	return (0);
}
