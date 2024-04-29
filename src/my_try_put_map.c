#include "../inc/cub3D.h"

void	find_distance_to_wall(char **map, t_raycaster *rc)
{
	while (!rc->hit)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->delta_dist_x;
			rc->map_x += rc->step_x;
			rc->side = false;
		}
		else
		{
			rc->side_dist_y += rc->delta_dist_y;
			rc->map_y += rc->step_y;
			rc->side = true;
		}
 
        printf("test %d %d\n", rc->map_y, rc->map_x);
		if (map[rc->map_y][rc->map_x] == '1')
			rc->hit = true;
	}
            printf("hhhhhtest\n");

}

void	find_wall_height(t_raycaster *rc)
{
	if (!rc->side)
		rc->perp_wall_dist = rc->side_dist_x - rc->delta_dist_x;
	else
		rc->perp_wall_dist = rc->side_dist_y - rc->delta_dist_y;
	rc->line_height = (int)(IMG_H / rc->perp_wall_dist);
	rc->draw_start = -rc->line_height / 2 + IMG_H / 2;
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	rc->draw_end = rc->line_height / 2 + IMG_H / 2;
	if (rc->draw_end >= IMG_H)
		rc->draw_end = IMG_H - 1;
}

void	find_wall_pixel(t_var *this, t_raycaster *rc)
{
	if (!rc->side)
		rc->wall_x = (int)this->player_y + rc->perp_wall_dist * rc->ray_dir_y;
	else
		rc->wall_x = (int)this->player_x + rc->perp_wall_dist * rc->ray_dir_x;
	rc->wall_x -= floor(rc->wall_x);
	rc->tex_x = (int)(rc->wall_x * (double)TEXTURE_WIDTH);
	if (!rc->side && rc->ray_dir_x > 0)
		rc->tex_x = TEXTURE_WIDTH - rc->tex_x - 1;
	if (rc->side && rc->ray_dir_y < 0)
		rc->tex_x = TEXTURE_WIDTH - rc->tex_x - 1;
	rc->step = 1.0 * TEXTURE_HEIGHT / rc->line_height;
	rc->tex_pos = (rc->draw_start - (IMG_H / 2) + rc->line_height / 2)
		* rc->step;
}

static  void	put_pixel_in_canvas(t_img *img, int x, int y,
	uint32_t color)
{
	char	*dst;

	dst = (char *) (img->img_addr + (y * img->size_line + x * (img->bits_per_pixel / 8)));
	*(uint32_t *)dst = color;
}

static int extract_pixel_from_image(t_img *img,
		int point_x, int point_y)
{
	return (*(uint32_t *)(img->img_addr
		+ (point_y * img->size_line) + (point_x * img->bits_per_pixel / 8)));
}
static uint32_t	get_color(t_var *this, t_raycaster *rc)
{
	if (!rc->side)
	{
		if (this->player_x > rc->map_x)
			return (extract_pixel_from_image(this->west,
					rc->tex_x, rc->tex_y));
		return (extract_pixel_from_image(this->east,
				rc->tex_x, rc->tex_y));
	}
	if (this->player_y > rc->map_y)
		return (extract_pixel_from_image(this->north,
				rc->tex_x, rc->tex_y));
	return (extract_pixel_from_image(this->sourth,
			rc->tex_x, rc->tex_y));
}

static void	draw_vertical_line(t_var *this, t_raycaster *rc, int x, t_img canvas)
{
	int	y;

	y = -1;
	while (++y < rc->draw_start)
	{
		put_pixel_in_canvas(&canvas, x, y,
			create_trgb(256, this->ceil[0],
				this->ceil[1], this->ceil[2]));
	}
	y = rc->draw_start;
	while (y < rc->draw_end)
	{
		rc->tex_y = (int)rc->tex_pos & (TEXTURE_HEIGHT - 1);
		rc->tex_pos += rc->step;
		put_pixel_in_canvas(&canvas, x, y, get_color(this, rc));
		y += 1;
	}
	y = rc->draw_end;
	while (y < IMG_H)
	{
		put_pixel_in_canvas(&canvas, x, y,
			create_trgb(256, this->floor[0],
				this->floor[1], this->floor[2]));
		y += 1;
	}
}

void	point_rays(t_var *this, t_raycaster *rc)
{

	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (this->player_x - rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0f - this->player_x)
			* rc->delta_dist_x;
	}
	if (rc->ray_dir_y > 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (this->player_y - rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0f - this->player_y)
			* rc->delta_dist_y;
	}
}


static void	init_rc(t_var *this, t_raycaster *rc, int x, t_camera *camera)
{
	rc->camera_x = 2 * x / (double)IMG_W - 1;
	rc->ray_dir_x = camera->dir_x + camera->plane_x * rc->camera_x;
	rc->ray_dir_y = camera->dir_y + camera->plane_y * rc->camera_x;
	rc->map_x = (int)this->player_x ;
	rc->map_y = (int)this->player_y;
	rc->delta_dist_x = fabs(1 / rc->ray_dir_x);
	rc->delta_dist_y = fabs(1 / rc->ray_dir_y);
	rc->hit = false;
}
static t_img	new_img(void *mlx_ptr)
{
	t_img	new_img;

	new_img.img_ptr = mlx_new_image(mlx_ptr, IMG_W, IMG_H);
	new_img.img_addr = (int *) mlx_get_data_addr(new_img.img_ptr, &new_img.bits_per_pixel,
			&new_img.size_line, &new_img.endian);
	return (new_img);
}
static void	draw_square(t_img *canva, int x, int y, int color)
{
	size_t	i;
	size_t	j;

	i = MINIMAP_SQUARES_PADDING;
	while (i < 4 + MINIMAP_SQUARES_PADDING)
	{
		j = MINIMAP_SQUARES_PADDING;
		while (j < 4 + MINIMAP_SQUARES_PADDING)
		{
			put_pixel_in_canvas(canva, (x * 8 + i), (y * 8 + j), color);
			j += 1;
		}
		i += 1;
	}
}

static void	draw_minimap(t_var *this, t_img canvas)
{
	int	x;
	int	y;
	int	map_length;
    int map_height;

    map_height = double_ft_len(this->map);

	y = 0;
	while (y < map_height)
	{
		x = 0;
		map_length = ft_strlen(this->map[y]);
		while (x < map_length)
		{
			if (x == (int)this->player_x && y == (int)this->player_y)
				draw_square(&canvas, x, y, YELLOW);
			else if (this->map[y][x] == '1')
				draw_square(&canvas, x, y, WHITE);
			x += 1;
		}
		y += 1;
	}
}

static void	render_frame1(t_var *this, t_camera *camera)
{
	int			x;
	t_raycaster	rc;
    t_img       canvas;

	canvas = new_img(this->mlx_init_ptr);
	x = 0;

	while (x < IMG_W)
	{
		init_rc(this, &rc, x, camera);
		point_rays(this, &rc);

		find_distance_to_wall(this->map, &rc);
                        printf("rtes\n");

		find_wall_height(&rc);
		find_wall_pixel(this, &rc);

		draw_vertical_line(this, &rc, x, canvas);
		x += 1;
	}
	draw_minimap(this, canvas);
	mlx_clear_window(this->mlx_init_ptr, this->win_init_ptr);
	mlx_put_image_to_window(this->mlx_init_ptr, this->win_init_ptr,
		canvas.img_ptr, 0, 0);
}


int	window_loop(t_var *this, t_camera *camera)
{
    //     this->player_x += 0.5;
    // this->player_y += 0.5;
	render_frame1(this, camera);

	return (EXIT_SUCCESS);
}