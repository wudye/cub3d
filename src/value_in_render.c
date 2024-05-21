#include "../inc/cub3D.h"

static t_coordinate get_sum_vector(t_var *var, t_render *ren, t_coordinate *src, t_coordinate *dest)
{
    t_coordinate res;
    double  distance;

    dest->d_x = ren->left_side_ray.d_x + src->d_x;
    dest->d_y = ren->left_side_ray.d_y + src->d_y;
    res.d_x = var->player.direction_x + dest->d_x;
    res.d_y = var->player.direction_y + dest->d_y;
    distance = sqrtf(res.d_x * res.d_x + res.d_y * res.d_y);
    res.d_x = res.d_x * (1 / distance);
    res.d_y = res.d_y * (1 / distance);
    return (res);
}


static void apply_dda(t_var *var)
{
    t_render *ren;
    t_coordinate *sum_ray;
    t_coordinate add;
    t_coordinate add_copy;
    int st;

    ren = var->ren;

    st = 0;
    sum_ray = ft_calloc((IMG_W + 1), sizeof(t_coordinate));
    coordinate_x_y(1 / ((double)IMG_W - 1) * 2, &add, ren->right_side_ray);    
    // printf("%f %f %f %f\n", ren->right_side_ray.d_x, ren->right_side_ray.d_y, add.d_x, add.d_y);
    while (st < IMG_W)
    {
        coordinate_x_y((double)st, &add_copy, add);
                //  printf("after %f %f %f %f\n",add.d_x, add.d_y, add_copy.d_x, add_copy.d_y);

        ren->rays[st] = get_sum_vector(var, ren, &add_copy, &sum_ray[st]); 
        // printf("%d %f %f\n", st, ren->rays[st].d_x, ren->rays[st].d_y);
        ren->hits[st] = dda_main(var, ren->rays[st]);
        // printf("%f\n", ren->hits[st].hit_pos.d_x);
        // printf("%d %f\n", st, ren->hits[st].perpWallDist);
        st++;
    }
    free(sum_ray);


}

void hit_value_set(t_var *var)
{
    t_render *ren;

    int st;

    ren = var->ren;

    st = 0;

    while (st < IMG_W)
    {
                //  printf("after %f %f %f %f\n",add.d_x, add.d_y, add_copy.d_x, add_copy.d_y);

        // printf("%d %f %f\n", st, ren->rays[st].d_x, ren->rays[st].d_y);
        ren->hits[st] = dda_main(var, ren->rays[st]);
        // printf("%f\n", ren->hits[st].hit_pos.d_x);
        printf("%d %f\n", st, ren->hits[st].perpWallDist);
        // if (ren->hits[st].perpWallDist == 0.95)
            // break;
        st++;
    }
}
void value_in_render(t_var *var)
{
    t_render *ren;

    ren = var->ren;
    ren->rays = ft_calloc(IMG_W + 1, sizeof(t_coordinate));
    ren->hits = ft_calloc(IMG_W + 1, sizeof(t_hit));
    vectot_rotate_by_angle(&ren->left_side_ray, (-M_PI / 2), var->player, (FOV / 90.0));
    vectot_rotate_by_angle(&ren->right_side_ray, (M_PI / 2), var->player, (FOV / 90.0));
    apply_dda(var);
    hit_value_set(var);
}