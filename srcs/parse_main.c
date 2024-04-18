#include "cub3D.h"

static int  get_file_length(int fd)
{
    int     i;
    char    *temp;

    i = 0;
    while (1)
    {
        temp = get_next_line(fd);
        if (temp && ft_strncmp(temp, "\n", 2) == 0)
        {     
            free(temp);
            continue;
        }
        if (temp == NULL)
            break ;
        i++;
        free(temp);
    }
    if (temp)
        free(temp);
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
        str[i] = ft_strtrim(t2, "\n");
        free(t2);
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

static void set_data_value(int fd, t_var *var, int len)
{
    char    *temp;

    var->texture = malloc(sizeof(char *) * 7);
    if (!var->texture)
        error_malloc(var);
    set_data_value_helper(fd, var->texture, 6, var);
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
}

static int  open_map_file(char *filename, t_var *var)
{
    int     fd;
    int     len;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return(err_return_info("Error can not open the map", var));
    len = get_file_length(fd);
    if (len == 0)
        return(err_return_info("Error empty map", var));
    close (fd);
    fd = open(filename, O_RDONLY);
    set_data_value(fd, var, len);
    close(fd);
    return (0);
}

int    parse_main(t_var *var, char **argv)
{

    if (parse_argv(argv[1]) == 1)
        return (err_return_info("Error need a cub type map", var));


    if (open_map_file(argv[1], var) == 1)
        return (1);


    if (check_texture(var, var->texture) == 1)
        return (err_return_info("Error texture format wrong", var));
    // if (check_color(var->texture) == 1)
    //     return (1);
    // if (check_map(var->texture) == 1)
    //     return (1);
    
// {
//     printf("---test----\n");
//     int i = 0;
//     while(var->texture[i]!= NULL)
//     {
//         printf("test %s\n", var->texture[i]);
//         i++;
//     }
    
// }
    

    printf("finish test------ \n");
    return (0);
}
