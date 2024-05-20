#include "../inc/cub3D.h"


void draw_ceil_floor(t_img *img, t_step *sxy, int limit, int cf[3])
{
    char *data;
    unsigned int color;
    printf("test\n");
    while (sxy->y < limit)
    {
        data = img->img_addr;
        data += (sxy->y * img->size_line + sxy->x * (img->bits_per_pixel / 8));
        color = change_int_to_rgb(cf[0], cf[1], cf[2]);
        *data = color;
        sxy->y++;
    }
}



