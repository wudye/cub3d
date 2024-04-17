#include "cub3D.h"

static int  check_texture_directions(char **str, char *compare)
{

}

static int  check_texture_content(char *st, int i, t_var *var)
{
    char    **str;

    str = ft_split(st, ' ');
    if (!str)
        error_malloc(var);
    if (double_ft_len(str) != 2)
    {
        free_double_ptr(str);
        return (1);
    }
    if (i == 0)
        return (check_texture_directions(str, "NO"));
    if (i == 1)
        return (check_texture_directions(str, "SO"));
    if (i == 2)
        return (check_texture_directions(str, "WE"));
    if (i == 3)
        return (check_texture_directions(str, "EA"));
    if (i == 4)
        return (check_texture_color(str, "F"));
    if (i == 5)
        return (check_texture_color(str, "C"));
    return (0);
}

int check_texture(t_var *var, char **texture)
{
    int i;

    i = 0;
    while (texture[i])
    {
        if (check_texture_content(texture[i], i, var) == 1)
            return (err_return_info("texture format wrong", var));
        i++;
    }
    return (0);
}