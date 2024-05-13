/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:27:50 by cthaler           #+#    #+#             */
/*   Updated: 2024/04/24 09:27:50 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
/*
Numbers returned by this function can be passed as the color parameter
 in the TextColor or TextColorRemove functions. 
 The RGB function uses the following formula to calculate the result:
red * 2562 + green * 256 + blue 
where 2562 = 65536

    - Red component   : bits 24-31 (hexadecimal mask `0xff000000`)
    - Green component : bits 16-23 (hexadecimal mask `0x00ff0000`)
    - Blue component  : bits  8-15 (hexadecimal mask `0x0000ff00`)
using binary
	return (t << 24 | r << 16 | g << 8 | b);

*/
int	change_int_to_rgb(int r, int g, int b)
{
    return (r * 256 * 256 + g * 256 + b);
    
}
