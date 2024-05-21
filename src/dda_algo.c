#include "../inc/cub3D.h"

static void set_step_sidedist(t_var *var, t_coordinate ray, t_hit *res)
{


    if (ray.d_x < 0)
    {
        res->step.x = -1;
        res->sideDist.d_x = (var->player.position_x - (int) var->player.position_x) * res->deltaDist.d_x;
    }
    else
        res->sideDist.d_x = (1 - var->player.position_x + (int) var->player.position_x) * res->deltaDist.d_x;        
    if (ray.d_y < 0)
    {
        res->step.y = -1;
        res->sideDist.d_y = (var->player.position_y - (int) var->player.position_y) * res->deltaDist.d_y;
    }
    else
        res->sideDist.d_y = (1 - var->player.position_y + (int) var->player.position_y) * res->deltaDist.d_y;
}

void  init_hit_value(t_var *var, t_coordinate ray, t_hit *res)
{

    res->deltaDist.d_x = __DBL_MAX__;
    res->deltaDist.d_y = __DBL_MAX__;
    if (ray.d_x != 0)
        res->deltaDist.d_x = fabs(1 / ray.d_x);
    if (ray.d_y != 0)
        res->deltaDist.d_y = fabs(1 / ray.d_y);
    res->step.x = 1;
    res->step.y = 1;
    res->sideDist.d_x = 0;
    res->sideDist.d_y = 0;
    set_step_sidedist(var,ray, res);
    res->ray_map.x = (int)var->player.position_x;
    res->ray_map.y = (int)var->player.position_y;

}

t_hit dda_main_help(t_var *var, t_coordinate ray, t_hit fo)
{
    t_hit hit;

    hit.deltaDist = fo.deltaDist;
    // hit.perpWallDist = fo.perpWallDist;
    hit.sideDist = fo.sideDist;
    hit.hit_pos.d_x =var->player.position_x + ray.d_x * fo.pre_dist;
    hit.hit_pos.d_y = var->player.position_y + ray.d_y * fo.pre_dist;
    hit.perpWallDist = fo.pre_dist * (ray.d_x * var->player.direction_x + \
    ray.d_y * var->player.direction_y);
    // printf("gg %f\n", hit.perpWallDist);
    if (fo.hit_side == 'E')
    {
        if (ray.d_x > 0)
            hit.hit_side = WEST;
        else
            hit.hit_side = EAST;
    }
    else
    {
        if (ray.d_y > 0)
            hit.hit_side = NORTH;
        else
            hit.hit_side = SOURTH;
    }
    return (hit);
}

t_hit dda_main(t_var *var, t_coordinate ray)
{

    t_hit   res;
    t_hit   help;

    init_hit_value(var, ray,  &help);
        // printf("%f %f %f %f %f \n", res.pre_dist,res.deltaDist.d_x, res.deltaDist.d_y, res.sideDist.d_x, res.sideDist.d_y);
    res.hit_side = '5';

    while (res.hit_side == '5')
    {
        if (help.sideDist.d_x < help.sideDist.d_y)
        {
            help.pre_dist = help.sideDist.d_x;
            help.sideDist.d_x += help.deltaDist.d_x;
            help.ray_map.x += help.step.x;
            help.hit_side = 'E';
        }
        else
        {
            help.pre_dist = help.sideDist.d_y;
            help.sideDist.d_y += help.deltaDist.d_y;
            help.ray_map.y += help.step.y;
            help.hit_side = 'N';
        }
        // printf("%f %f %f\n", res.pre_dist, res.sideDist.d_x, res.sideDist.d_y);
        // printf("tt%d %d\n", help.ray_map.x, help.ray_map.y);
        if (var->map[help.ray_map.y][help.ray_map.x] == '1')
            res = dda_main_help(var, ray, help);
    }
        // printf("%f %f %f %f\n", res.deltaDist.d_x, res.deltaDist.d_y, res.sideDist.d_x, res.sideDist.d_y);
    // printf("%f\n", res.perpWallDist);
    return (res);
}