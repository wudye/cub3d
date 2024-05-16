#ifndef MY_TRY_H
# define MY_TRY_H

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

#define WHITE 0xFFFAFA
#define BLACK 0x000000
#define YELLOW 0xFFFF00
#define MINIMAP_SQUARES_PADDING 4

typedef struct s_raycaster
{
	double	camera_x;
	double	perp_wall_dist;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	double	tex_pos;
	double	step;
}				t_raycaster;
typedef struct s_coordinate
{
    int i_x;
    int i_y;
    double d_x;
    double d_y;
} t_coordinate;

typedef struct s_wall
{
    double wallx;
    int hegiht;
    int top;
    int bottom;
} t_wall;

typedef struct s_texture
{
    int x;
    int y;
    double start;
    double step;
} t_texture;

typedef struct s_render
{
    t_coordinate map_pos;
    t_coordinate ray_dir;
    t_coordinate step;
    t_coordinate side_distance;
    t_coordinate delta_distance;
    t_wall  wall;
    int    touch;
    double  ray_x;
    int side;
    t_texture   tex;
    double pre_wall_distance;

} t_render;

#endif