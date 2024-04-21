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
    // var->north.img_ptr = NULL;
    // var->north.img_addr = NULL;
    // var->sourth.img_ptr = NULL;
    // var->sourth.img_addr = NULL;
    // var->west.img_ptr = NULL;
    // var->west.img_addr = NULL;
    // var->east.img_ptr = NULL;
    // var->east.img_addr = NULL;
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
    res->player_x = 0;
    res->player_y = 0;
    init_img(res);
    return (res);
}


// texture part should have an order provide two ways
// second way do not care about order
// should check player routines
// eg. at the beginning player is surronded by walls valid or not 
int main(int argc, char **argv)
{
    t_var   *var;

    var = NULL;
    if (argc == 2)
    {
        if (parse_argv(argv[1]) == 1)
            return (err_return_info("Error need a cub type map", var));
        var = init_var();
        if (!var)
            error_malloc(var);
        if (parse_main(var, argv) == 1)
            return ( 1);
        if (render_mlx(var) == 1)
            return (1);
        free_var(var);
        return (0);
    }
    return (err_return_info( "Error argument nums wrong", var));
}