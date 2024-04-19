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


void    destroy_mlxlib(t_var *var)
{

    if (var->north)
        mlx_destroy_image(var->mlx_init_ptr, var->north);
    if (var->sourth)
        mlx_destroy_image(var->mlx_init_ptr, var->sourth);
    if (var->east)
        mlx_destroy_image(var->mlx_init_ptr, var->east);
    if (var->west)
        mlx_destroy_image(var->mlx_init_ptr, var->west);
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
    free(var->ceil);
    free(var->floor);
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
