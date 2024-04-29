#ifndef MY_TRY_H
# define MY_TRY_H

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

#define WHITE 0xFFFAFA
#define BLACK 0x000000
#define YELLOW 0xFFFF00
#define MINIMAP_SQUARES_PADDING 4

typedef struct s_camera
{
    double   plane_x;
    double plane_y;
    double dir_x;
    double dir_y;
} t_camera;


typedef struct s_raycaster
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
}				t_raycaster;




#endif