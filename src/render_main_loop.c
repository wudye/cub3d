#include "../inc/cub3D.h"

int render_loop(t_var *var)
{
    t_raycaster ray;

    var->img.img_ptr = mlx_new_image(var->mlx_init_ptr, IMG_W, IMG_H);
	if (!var->img.img_ptr)
		return (error_malloc(var), 1);
	var->img.img_addr = (int *)mlx_get_data_addr(var->img.img_ptr,
		&var->img.bits_per_pixel, &var->img.size_line, &var->img.endian);
    (void) ray;
    // dda application
    // put texture
    return (EXIT_SUCCESS);
}