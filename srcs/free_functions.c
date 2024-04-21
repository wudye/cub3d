#include "cub3D.h"

void free_double_ptr(char **str)
{
    int i;

    i = 0;
    if (!str || !str[0])
        return ;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

static void free_img(t_var *var, t_img *img)
{
    if (img->img_ptr)
        mlx_destroy_image(var->mlx_init_ptr, img->img_ptr);
    // if (img->img_addr)
    //     free(img->img_addr);
    free(img);

}

void    destroy_mlxlib(t_var *var)
{

    if (var->north)
        free_img(var, var->north);
    if (var->sourth)
        free_img(var, var->sourth);
    if (var->west)
        free_img(var, var->west);
    if (var->east)
        free_img(var, var->east);
    // if (var->north->img_ptr)
    //     mlx_destroy_image(var->mlx_init_ptr, var->north->img_ptr);
    // if (var->sourth->img_ptr)
    //     mlx_destroy_image(var->mlx_init_ptr, var->sourth->img_ptr);
    // if (var->east->img_ptr)
    //     mlx_destroy_image(var->mlx_init_ptr, var->east->img_ptr);
    // if (var->west->img_ptr)
    //     mlx_destroy_image(var->mlx_init_ptr, var->west->img_ptr);
    if (var->win_init_ptr)
        mlx_destroy_window(var->mlx_init_ptr, var->win_init_ptr);
    if (var->mlx_init_ptr)
    {
        mlx_destroy_display(var->mlx_init_ptr);
        free(var->mlx_init_ptr);
    }

}
void    free_var(t_var *var)
{
    if (!var)
        return ;
    destroy_mlxlib(var);
    free_double_ptr(var->map);
    free_double_ptr(var->texture);
    free(var);
}

void    error_malloc(t_var *var)
{
    ft_putstr_fd("malloc failed\n", 2);
    if (!var)
        exit(1);
    free_var(var);
    exit(1);
}

int err_return_info(char *str, t_var *var)
{
    ft_putstr_fd(str, 2);
    write(2, "\n", 1);
    free_var(var);
    return (1);
}
