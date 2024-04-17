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

int	init_map(char **argv);
char	*read_mapfile(int fd, int i_read);

#endif
