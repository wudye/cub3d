#ifndef CUB3D_H
# define CUB3D_H

# include <stddef.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdbool.h>

# include "../libft/libft.h"
# include "../minilibx_linux/mlx.h"
# include "../srcs/get_next_line.h"

# define player "NSEW"

typedef struct s_img
{
    void    *img_ptr;
    char    *img_addr;
    int     bits_per_pixel;
    int     size_line;
    int     endian;
}   t_img;

typedef struct s_var
{
    void    *mlx_init_ptr;
    void    *win_init_ptr;
    char    **texture;
    char    **map;
    int     floor[3];
    int     ceil[3];
    int     player_x;
    int     player_y;
    t_img   *north;
    t_img   *sourth;
    t_img   *west;
    t_img   *east;

}   t_var;


// typedef struct s_var
// {
//     void    *mlx_init_ptr;
//     void    *win_init_ptr;
//     char    **texture;
//     char    **map;
//     int     floor[3];
//     int     ceil[3];
//     int     player_x;
//     int     player_y;
//     t_img   north;
//     t_img   sourth;
//     t_img   west;
//     t_img   east;
    

    

// }   t_var;

int     main(int argc, char **arv);

// parse part
int     parse_main(t_var *var, char **argv);
int     parse_argv(char *str);
int     double_ft_len(char **str);
int     check_texture(t_var *var, char **texture);
int     check_color_value(char *str, int *color);
int     check_map_numbers(t_var *var, char **map);
int     handle_spaces(char **map, t_var *var);
int     handle_walls(t_var *var, char **map);
int     handle_inner_zero(char **map, t_var *var);
int	get_file_length1(int fd, int len);
void    exchange_helper(char *temp, char **str, int i);

// render
int     render_mlx(t_var *var);


// free functions
void    error_malloc(t_var *var);
void    free_var(t_var *var);
int err_return_info(char *str, t_var *var);
void free_double_ptr(char **str);



#endif
