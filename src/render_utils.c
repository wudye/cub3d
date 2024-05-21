#include "../inc/cub3D.h"


int longest_colum(char **map)
{
    int curr_len;
    int max_len;
    int i;

    i = 0;
    max_len = ft_strlen(map[i]);
    while (map[i])
    {
        curr_len = ft_strlen(map[i]);
        if (max_len < curr_len)
            max_len = curr_len;
        i++;
    }
    return (max_len);
}
 
unsigned int texture_pixel(t_img *tex, t_coordinate tex_range)
{
    unsigned int *res;

    res = (unsigned int *) tex->img_addr;
    res += (unsigned int)(64 * tex_range.d_x) + (int)(tex_range.d_y * 64) *64;
    return (*res);
}

void	*pixel_ptr(t_img *img, int x, int y)
{
	char	*res;

	res = (char *)img->img_addr;
	res += (y * img->size_line + x * (img->bits_per_pixel / 8));
	return (res);
}