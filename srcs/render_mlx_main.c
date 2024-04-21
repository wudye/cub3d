#include "cub3D.h"

int render_mlx(t_var *var)
{
    var->win_init_ptr = mlx_new_window(var->mlx_init_ptr, 1900, 1600, "cub3D");
    if (!var->mlx_init_ptr)
        return (err_return_info("Error win_ptr fail", var));
    return (0);
}
