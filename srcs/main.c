#include "cub3D.h"



static void zero_img_init(t_img *img)
{
    img->img_addr =  NULL;
    img->img_ptr = NULL;
    img->bits_per_pixel = 0;
    img->endian = 0;
    img->size_line = 0;
}

static void init_img(t_var *var)
{
    var->east = malloc(sizeof(t_img));
    if (!var->east)
        error_malloc(var);
    zero_img_init(var->east);
    var->west = malloc(sizeof(t_img));
    if (!var->west)
        error_malloc(var);
    zero_img_init(var->west);
    var->sourth = malloc(sizeof(t_img));
    if (!var->sourth)
        error_malloc(var);
    zero_img_init(var->sourth);
    var->north = malloc(sizeof(t_img));   
    if (!var->north)
        error_malloc(var);
    zero_img_init(var->north);
}

static t_var *init_var()
{
    t_var   *res;

    res = malloc(sizeof(t_var));
    if (!res)
        error_malloc(res);
    res->mlx_init_ptr = mlx_init();
    if (!res->mlx_init_ptr)
        error_malloc(res);
    res->win_init_ptr = NULL;
    res->map = NULL;
    res->texture = NULL;
    init_img(res);
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
        
        var->win_init_ptr = mlx_new_window(var->mlx_init_ptr, 1900, 1600, "cub3D");
        if (!var->mlx_init_ptr)
            return (err_return_info("Error win_ptr fail", var));
        printf("end in main %d\n", var->ceil[0]);
        printf("end in main %d\n", var->ceil[1]);
        printf("end in main %d\n", var->ceil[2]);
   
        return (0);
    }
    return (err_return_info( "Error argument nums wrong", var));
}