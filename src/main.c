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
	if (argc != 2)
		return (err("Error: invalid nr of args\n"));
	if (init_map(argv))
		return (err("Error: init map failed\n"));
	return (0);
}
