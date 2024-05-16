#include "../inc/cub3D.h"

static void canvas_value_set(t_var *var)
{
    var->img->img_ptr = mlx_new_image(var->mlx_init_ptr, IMG_W, IMG_H);
	if (!var->img->img_ptr)
		return (error_malloc(var));
	var->img->img_addr = mlx_get_data_addr(var->img->img_ptr,
		&var->img->bits_per_pixel, &var->img->size_line, &var->img->endian);
}

static void set_side_distance(t_var *var, t_render *ren)
{
    
    // should figure out why -1
    if (ren->ray_dir.d_x < 0)
    {
        ren->step.i_x = -1;
        ren->side_distance.d_x = (var->player.position_x - ren->map_pos.i_x - 1) * ren->delta_distance.d_x;
    }
    else
    {
        ren->step.i_x = 1;
        ren->side_distance.d_x = (var->player.position_x + 1.0 - ren->map_pos.i_x - 1) * ren->delta_distance.d_x;
    }
    if (ren->ray_dir.d_y < 0)
    {
        ren->step.i_y = -1;
        ren->side_distance.d_y = (var->player.position_y - ren->map_pos.i_y - 1) * ren->delta_distance.d_y;
    }
    else
    {
        ren->step.i_y = 1;
        ren->side_distance.d_y = (var->player.position_y + 1.0 - ren->map_pos.i_y -1 ) * ren->delta_distance.d_y;
    }

}

static void DDA_algorithm(t_var *var, t_render *ren)
{
        //     printf("test  %f %f %f %d %d %f %f %f %f\n", ren->ray_x, ren->ray_dir.d_x, ren->ray_dir.d_y, ren->map_pos.i_x, ren->map_pos.i_y,     ren->delta_distance.d_x,     ren->delta_distance.d_y
        // ,ren->side_distance.d_x, ren->side_distance.d_y);
    while (ren->touch == 0)
    {
        if (ren->side_distance.d_x < ren->side_distance.d_y)
        {
            ren->side_distance.d_x += ren->delta_distance.d_x;
            ren->map_pos.i_x += ren->step.i_x;
            ren->side = 0;
        }
        else
        {
            ren->side_distance.d_y += ren->delta_distance.d_y;
            ren->map_pos.i_y += ren->step.i_y;
            ren->side = 1;
        }
        if (var->map[ren->map_pos.i_y][ren->map_pos.i_x] == '1')
            ren->touch = 1;
    }


}

static void side_condition(t_var *var, t_render *ren)
{
    if (ren->side == 0)
    {
        ren->pre_wall_distance = ren->side_distance.d_x - ren->delta_distance.d_x;
        ren->wall.wallx = var->player.position_y + ren->pre_wall_distance * ren->ray_dir.d_y;

    }
    else
    {
        ren->pre_wall_distance = ren->side_distance.d_y - ren->delta_distance.d_y;
        ren->wall.wallx = var->player.position_x + ren->pre_wall_distance * ren->ray_dir.d_x;
    }
    ren->wall.wallx -= floor(ren->wall.wallx);

}
static void value_set(t_var *var, t_render *ren, int n)
{
    
    ren->ray_x = 2 * n / (double) IMG_W - 1;
    ren->ray_dir.d_x = var->player.direction_x + var->camerax * ren->ray_x;
    ren->ray_dir.d_y = var->player.direction_y + var->cameray * ren->ray_x;
    ren->map_pos.i_x = (int) var->player.position_x;
    ren->map_pos.i_y = (int) var->player.position_y;
    ren->delta_distance.d_x = fabs(1 / ren->ray_dir.d_x);
    ren->delta_distance.d_y = fabs(1 / ren->ray_dir.d_y);
    ren->touch = 0;
    set_side_distance(var, ren);
    DDA_algorithm(var, ren);
    side_condition(var, ren);

}
static void set_wall_texture_value(t_render *ren)
{
    ren->wall.hegiht = (int) (IMG_H / ren->pre_wall_distance);
    // should compensate the init +0.5
    ren->wall.top = (IMG_H - ren->wall.hegiht ) / 2;
    
    printf("test %d %d %f %d\n",IMG_H, ren->wall.hegiht, ren->pre_wall_distance, ren->wall.top );

    if (ren->wall.top < 0)
        ren->wall.top = 0;
    ren->wall.bottom = (ren->wall.hegiht + IMG_H) / 2;
    if (ren->wall.bottom < 0)
        ren->wall.bottom = 0;
    ren->tex.x = (int) (ren->wall.wallx * 64);
    if (ren->side == 0 && ren->ray_dir.d_x > 0)
        ren->tex.x = 64 - ren->tex.x - 1;
    if (ren->side && ren->ray_dir.d_y < 0)
        ren->tex.x = 64 - ren->tex.x - 1;
    ren->tex.step = 64 / ren->wall.hegiht;
    ren->tex.start = (ren->wall.top - IMG_H / 2 + ren->wall.hegiht / 2) * ren->tex.step;

}

// void  draw_sky_ceil(t_var *var, int c[3], int *y, int *x)
// {
//     while (*y < IMG_H)
//     {
//         var->img->img_addr +=  (*y) * var->img->size_line + (*x) *(var->img->bits_per_pixel / 8);
//         *(unsigned int *)var->img->img_addr  = change_int_to_rgb(c[0], c[1], c[2]);
//         (*y)++;
//     }
    


// }
void draw_map(t_var *var, t_render *ren, int x)
{
    int y;
    y = 0;
            char *temp;

    while (y < ren->wall.top)
    {
        temp = var->img->img_addr +  (y) * var->img->size_line + (x) *(var->img->bits_per_pixel / 8);
        *(unsigned int *)temp  = change_int_to_rgb(var->ceil[0], var->ceil[1], var->ceil[2]);
        y++;
    }
    
    // draw_sky_ceil(var, var->ceil, &y, &x);
    // draw_sky_ceil(var, var->floor, &y, &x);

}

int render_loop(t_var *var)
{
    t_coordinate start_pos;
    t_render    ren;
            // char *temp;

    start_pos.i_x = 0;
    canvas_value_set(var);
    while (start_pos.i_x < IMG_W)
    {
        start_pos.i_y = 0;
        value_set(var,&ren, start_pos.i_x);

    set_wall_texture_value(&ren);

        draw_map(var, &ren, start_pos.i_x);

//  while (start_pos.i_y < ren.wall.top)
//     {
//         temp = var->img->img_addr +  (start_pos.i_y) * var->img->size_line + (start_pos.i_x) *(var->img->bits_per_pixel / 8);
//         *(unsigned int *)temp  = change_int_to_rgb(var->ceil[0], var->ceil[1], var->ceil[2]);
//         start_pos.i_y++;
//     }
//     start_pos.i_y = ren.wall.bottom;
//     while (start_pos.i_y < IMG_H)
//     {
//         temp = var->img->img_addr +  (start_pos.i_y) * var->img->size_line + (start_pos.i_x) *(var->img->bits_per_pixel / 8);
//         *(unsigned int *)temp  = change_int_to_rgb(var->ceil[0], var->ceil[1], var->ceil[2]);
//         start_pos.i_y++;
//     }
        start_pos.i_x++;
    }
    mlx_put_image_to_window(var->mlx_init_ptr, var->win_init_ptr, var->img->img_ptr, 0, 0);
    return (EXIT_SUCCESS);
}