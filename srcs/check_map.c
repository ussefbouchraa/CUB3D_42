/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 02:32:40 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/13 02:44:31 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void map_items(char **map)
{
    int i;
    int j;

    i = -1;
    if(!map || !map[0])
        return ;
    while(map[++i])
    {
        j = -1;
        while(map[i][++j])
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
            {
                if (map[i][j] != 'N' && map[i][j] != 'W' && map[i][j] != 'S' && map[i][j] != 'E')
                    ft_puterr("Error: Invalid Map E !!");
            }  
        }
    }     
}

// void map_border( t_map *vars, char **map, int height)
// {
//     int i;
//     int j;
//     j = -1;
//     while (map[0][++j])
//     {
//         if (map[0][j] != '1')
//             ft_puterr("Error: Invalid Map T");
//     }
//     j = -1;
//     while (map[height][++j])
//     {
//         if (map[height][j] != '1')
//             ft_puterr("Error: Invalid Map B");
//     }
//     i = -1;
//     while (map[++i][0])
//     {
//         if (map[i][0] != '1') 
//             ft_puterr("Error: Invalid Map L");
//     }
//     // i = -1;
//     // while (map[i][vars->width])
//     // {
//     //     if (map[i][vars->width] != '1') 
//     //         ft_puterr("Error: Invalid Map R");
//     // }
// }

// void check_map(t_map *vars)
// {
//     map_items(vars->map);
//     map_border(vars, vars->map, vars->height -1);
    
//     print_map(vars);
    
// }