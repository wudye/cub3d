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

void    free_var(t_var *var)
{
    if (!var)
        return ;
    free_double_ptr(var->map);
    free_double_ptr(var->texture);
    if (var->mlx_init_ptr)
    {
        mlx_destroy_display(var->mlx_init_ptr);
        free(var->mlx_init_ptr);
    }
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
