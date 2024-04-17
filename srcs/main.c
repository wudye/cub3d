#include "cub3D.h"

static t_var *init_var()
{
    t_var   *res;

    res = malloc(sizeof(t_var));
    if (!res)
        error_malloc(res);
    res->mlx_init_ptr = mlx_init();
    if (!res->mlx_init_ptr)
        error_malloc(res);
    res->map = NULL;
    res->texture = NULL;
    return (res);
}

int main(int argc, char **argv)
{
    t_var   *var;

    var = init_var();
    if (!var)
        error_malloc(var);
    if (argc == 2)
    {
        if (parse_main(var, argv) == 1)
            return (1);
        free_var(var);
        return (0);
    }
    return (err_return_info( "Error argument nums wrong", var));
}