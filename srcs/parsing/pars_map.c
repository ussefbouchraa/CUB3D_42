/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:15:00 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/21 22:41:20 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void map_err(t_info *info, char **map, char *msg)
{
    ft_puterr(msg);
    ft_clearr(map);
    free_items(info);
}
void map_border(t_info *info, char **map, int height, int width)
{
    printf("%c\n",map[0][width - 1])
;
    int i;
    int j;
    j = -1;
    while (map[0][++j])
    {
        if (map[0][j] != '1' && map[0][j] != ' ')
           map_err(info, map, "Error: Invalid Map T ");
    }
    j = -1;
    while (map[height][++j])
    {
        if (map[height][j] != '1' && map[height][j] != ' ')
           map_err(info, map, "Error: Invalid Map B");
    }
    i = -1;
    while (map[++i][0])
    {
        if (map[i][0] != '1'  && map[i][0] != ' ') 
            map_err(info, map, "Error: Invalid Map L");
    }
    i = -1;
    while (map[++i][width])
    {
        if (map[i][width] != '1' && map[i][width] != ' ') 
            ft_puterr("Error: Invalid Map R");
    }
}

void fill_map(t_info *info , t_map *vars)
{
    int size;
    char *spaces;
    int start;
    int j;

    start = skip_items(info->file);
    j  = -1;
    size = 0;
    while (info->file[start])
    {
            size = vars->max_width - ft_strlen(info->file[start]);
            if(size == 0)
                vars->map[j] = ft_strdup(info->file[start]);
            else
            {
                spaces = get_spaces(size);
                vars->map[++j] = ft_strjoin(info->file[start], spaces);
                free(spaces);
            }
    start++;
    }
    vars->map[++j] = NULL;
}
void read_map(t_info *info, t_map *vars)
{
    vars->height = height_map(info->file);
    vars->max_width = max_width(info->file);
    if(!vars->height)
    {
        free_items(info);
        ft_puterr("Error: empty Map !");
    }
    vars->map = malloc(sizeof(char*) * (vars->height + 1));
    if(!vars->map)
        {
            free_items(info);
            ft_puterr("Error: allocation failed !");  
        }
    fill_map(info, vars);
}



void check_items(t_info *info, char   **map)
{
    int i;
    int cp;

    cp = 0;
    i = -1;
    while(map[++i])
    {
        if(ft_strchr(map[i], 'N'))
            cp++;
        if(ft_strchr(map[i], 'W'))
            cp+=2;
        if(ft_strchr(map[i], 'S'))
            cp+=3;
        if(ft_strchr(map[i], 'E'))
            cp+=4;
        if(ft_strchr(map[i], 'P'))
            cp-=11;
    }
    if(cp != -1 || !valid_char(map))
    {
        ft_clearr(map);
        free_items(info);
        ft_puterr("Error:\n Invalid Map Items !");
    }
}
void check_map(t_map *vars, t_info *info)
{
    read_map(info, vars);
    check_items(info, vars->map);
    // print_map(vars->map); 
    map_border(info, vars->map, vars->height - 2, vars->max_width);
    

    // ft_clearr(vars->map);
}