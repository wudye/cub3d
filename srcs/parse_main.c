#include "cub3D.h"

static int  get_file_length1(int fd, int len)
{
    int     i;
    char    *temp;
    char    *temp1;
    int     j;

    j = 0;
    i = 0;
    while (1)
    {
        temp = get_next_line(fd);
        if (temp == NULL)
            break ;
        temp1 = ft_strtrim(temp, " ");
        free(temp);
        temp = ft_strtrim(temp1, "\t");
        free(temp1);
        if (temp && ft_strncmp(temp, "\n", 2) == 0)
        {
            free(temp);
            if (i > 6 && i < len)
                j++;
            continue;
        }
        i++;
        free(temp);
    }
    if (i - 6 == 0)
        return (-1);
    if (j > 0)
        return (-1);
    return (i);
}

static int  get_file_length(int fd)
{
    int     i;
    char    *temp;
    char    *temp1;

    i = 0;
    while (1)
    {
        temp = get_next_line(fd);
        if (temp == NULL)
            break ;
        temp1 = ft_strtrim(temp, " ");
        free(temp);
        temp = ft_strtrim(temp1, "\t");
        free(temp1);
        if (temp && ft_strncmp(temp, "\n", 2) == 0)
        {
            free(temp);
            continue;
        }
        i++;
        free(temp);
    }
    return (i);
}

static void set_data_value_helper(int fd, char **str, int len, t_var *var)
{
    char    *temp;
    char    *t2;
    int     i;
    
    i = 0;
    while (1)
    {
        temp = get_next_line(fd);
        if (temp && ft_strncmp(temp, "\n", 2) == 0)
        {
            free(temp);
            continue ;
        }
        if (temp == NULL)
            break ;
        t2 = ft_strtrim(temp, " ");
        free(temp);
        temp = ft_strtrim(t2, "\t");
        free(t2);
        str[i] = ft_strtrim(temp, "\n");
        free(temp);
        if (!str[i])
        {
            error_malloc(var);
        }
        i++;
        if (i  == len)
            break;
    }
    str[i] = 0;
}

static int set_data_value(int fd, t_var *var, int len)
{
    char    *temp;

    var->texture = malloc(sizeof(char *) * 7);
    if (!var->texture)
        error_malloc(var);
    set_data_value_helper(fd, var->texture, 6, var);
    if (len - 6 == 0)
        return(err_return_info("Error no map", var));
    var->map = malloc(sizeof(char *) * (len - 6 + 1));
    if (!var->map)
        error_malloc(var);
    set_data_value_helper(fd, var->map, len - 6, var);
    while (1)
    {
        temp = get_next_line(fd);
        if (temp == NULL)
            break;
        free(temp);
    }
    return (0);
}

static int  open_map_file(char *filename, t_var *var)
{
    int fd;
    int len;
    int k;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return(err_return_info("Error can not open the map", var));
    len = get_file_length(fd);
    if (len == 0)
        return(err_return_info("Error empty map", var));
    close (fd);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return(err_return_info("Error can not open the map", var));
    k = get_file_length1(fd, len);
    if (k == -1)
        return(err_return_info("Error map has empty line", var));
    close (fd);
    fd = open(filename, O_RDONLY);
    if (set_data_value(fd, var, len) == 1)
        return (close(fd), 1);
    return (close(fd), 0);
}

int    parse_main(t_var *var, char **argv)
{
    if (open_map_file(argv[1], var) == 1)
        return (1);
    if (check_texture(var, var->texture) == 1)
        return (1);
    if (check_map_numbers(var, var->map) == 1)
        return (1);
    return (0);
}
