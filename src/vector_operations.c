#include "../inc/cub3D.h"

void coordinate_x_y(double step,  t_coordinate *add, t_coordinate src)
{
    add->d_x = src.d_x * step;
    add->d_y = src.d_y * step;
}


void vectot_rotate_by_angle(t_coordinate *ray, double angle, t_player player, double fov_rat)
{
    float x;
    float y;
    x = player.direction_x * fov_rat;
    y = player.direction_y * fov_rat;

    ray->d_x = x * cosf(angle) - y * sinf(angle);
    ray->d_y = x * sinf(angle) + y* cosf(angle);
    // printf("%f %f \n", ray->d_x, ray->d_y);

}