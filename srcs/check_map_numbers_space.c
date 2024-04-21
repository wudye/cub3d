#include "cub3D.h"

static bool  dfs_al(char **map, int j, int k)
{
    int row;
    int col;

    row = double_ft_len(map);
    col = ft_strlen(map[0]);

    if ((j - 1 >= 0 && j + 1 < row && k  - 1 >= 0 && k + 1 < col) 
    && ( map[j - 1][k] == '0' || map[j + 1][k] == '0' || map[j][k - 1] == '0' || map[j][k + 1] == '0'))
        return (false);
    else if (j + 1 == row && k - 1 >= 0 && k + 1 < col 
    && ( map[j - 1][k] == '0' || map[j][k - 1] == '0' || map[j][k + 1] == '0'))
        return (false);
    else if ((j - 1 >= 0 && j + 1 < row && k + 1 == col) 
    && ( map[j - 1][k] == '0' || map[j + 1][k] == '0' || map[j][k - 1] == '0'))
        return (false);
    return (true);
}
// handle spaces
int  handle_spaces(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == ' ')
            {    
                if (dfs_al(map, i, j) != true)
                    return (1);
                else
                    map[i][j] = '1';
            }
            j++;
        }
        i++;
    }
    return (0);
}
