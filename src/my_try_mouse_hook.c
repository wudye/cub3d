#include "../inc/cub3D.h"





static void	nor_camera(t_camera *camera)
{
	camera->plane_x = 0.66;
	camera->plane_y = 0;
	camera->dir_x = 0.0f;
	camera->dir_y = 1.0f;
}

static void	sou_camera(t_camera *camera)
{
	camera->plane_x = -0.66;
	camera->plane_y = 0;
    camera->dir_x = 0.0f;
	camera->dir_y = -1.0f;
}

static void	eas_camera(t_camera *camera)
{
	camera->plane_x = 0;
	camera->plane_y = -0.66;
	camera->dir_x = 1.0f;
	camera->dir_y = 0.0f;
}

static void	wes_camera(t_camera *camera)
{
	camera->plane_x = 0;
	camera->plane_y = 0.66;
	camera->dir_x = -1.0f;
	camera->dir_y = 0.0f;
}

void init_camera(t_var *var, t_camera *camera)
{
    if (var->direction == 'N')
        nor_camera(camera);
    if (var->direction == 'S')
        sou_camera(camera);
    if (var->direction == 'E')
        eas_camera(camera);
    if (var->direction == 'W')
        wes_camera(camera);
}



/*
the mouse moves to the middle
int	mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y);
** Move the cursor to the given location.
**
** @param	void *win_ptr	the window instance;
** @param	int  x			the x location to move to;
** @param	int  y			the y location to move to;
** @return	int				has no return value (bc).
*/

bool	assert_window_boundaries(t_var *var, int x,int y, double *old_x)
{
	if (y != IMG_H / 2)
		mlx_mouse_move(var->mlx_init_ptr, var->win_init_ptr, x, IMG_H / 2);
	if (x <= 50 || x >= IMG_W - 50)
	{
		*old_x = IMG_W / 2;
		mlx_mouse_move(var->mlx_init_ptr, var->win_init_ptr, IMG_W / 2, y);
		return (true);
	}
	return (false);
}
int mouse_hook(int x, int y, t_var *var, t_camera *camera)
{
	double			old_dir_x;
	double			old_plane_x;
	double			distance;
	static double	old_x = 0;

	old_dir_x = camera->dir_x;
	old_plane_x = camera->plane_x;
	if (assert_window_boundaries(var, x, y, &old_x))
		return (EXIT_SUCCESS);
	distance = (old_x - x) * 0.002;
	old_x = x;
	camera->dir_x = camera->dir_x * cos(distance)
		- camera->dir_y * sin(distance);
	camera->dir_y = old_dir_x * sin(distance)
		+ camera->dir_y * cos(distance);
	camera->plane_x = camera->plane_x * cos(distance)
		- camera->plane_y * sin(distance);
	camera->plane_y = old_plane_x * sin(distance)
		+ camera->plane_y * cos(distance);
	return (EXIT_SUCCESS);
}