#include "cub3D.h"


static bool check_int(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] > '9' || str[i] < '0')
            return (false);
        i++;
    }
    return (true);
}

int check_color_value(char *str, int *color)
{
    char    **split_str;
    int     i;
    int     temp;

    i = 0;
    split_str = ft_split(str, ',');
    if (!split_str)
        return (-1);
    if (double_ft_len(split_str) != 3)
        return (free_double_ptr(split_str), 1);
    while (split_str[i])
    {
        if (check_int(split_str[i]) == false)
            return (free_double_ptr(split_str), 1);
        temp = ft_atoi(split_str[i]);
        if (temp < 0 || temp > 255)
            return (free_double_ptr(split_str), 1);
        color[i] = temp;
        i++;  
    }
    free_double_ptr(split_str);
    return (0);
}