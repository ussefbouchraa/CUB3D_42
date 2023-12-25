/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:15:00 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/25 07:02:43 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void map_border(t_info *info, char **map, int height, int width)
{
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
    while (map[++i])
    {
        if (map[i][0] && map[i][0] != '1'  && map[i][0] != ' ') 
            map_err(info, map, "Error: Invalid Map L");
        if (map[i][ft_strlen(map[i]) - 1] != '1')
            ft_puterr("Error: Invalid Map R");
    }
}

void fill_map(t_info *info , t_map *vars)
{
    int start;
    int j;

    start = start_map(info->file);
    j  = 0;
    while (info->file[start])
    {
        vars->map[j++] = ft_strdup(info->file[start]);
        start++;
    }
    vars->map[j] = NULL;
}


int  height_map(char **f_map)
{
    int i;
    int len;
    int start;

    len = 0;
    start = start_map(f_map);
    if(start < 7)
        return(len);
    while (f_map[start])
    {
        len++;
        start++;
    }
    return(len);
}

void read_map(t_info *info, t_map *vars)
{
    vars->height = height_map(info->file);
    if(!vars->height)
    {
        free_items(info);
        ft_puterr("Error: Invalid Map !!");
    }
    vars->map = malloc(sizeof(char*) * (vars->height + 1));
    if(!vars->map)
        {
            free_items(info);
            ft_puterr("Error: allocation failed !!");  
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
            cp++;
        if(ft_strchr(map[i], 'S'))
            cp++;
        if(ft_strchr(map[i], 'E'))
            cp++;
    }
    if(cp != 1 || !valid_char(map))
    {
        ft_clearr(map);
        free_items(info);
        ft_puterr("Error: Invalid Map !!");
    }
}
void set_map(t_map *vars)
{
    int size;
    char *spaces;
    int i;
    int j;

    i = 0;
    j  = -1;
    vars->max_width = max_width(vars->map);
    while (vars->map[i])
    {
            size = vars->max_width - ft_strlen(vars->map[i]);
            if(size != 0)
            {
                spaces = get_spaces(size);
                vars->map[++j] = ft_strjoin(vars->map[i], spaces);
                free(spaces);
            }
            else
                vars->map[++j] = ft_strdup(vars->map[i]);      
        i++;
    }
    vars->map[++j] = NULL;
}

void check_map(t_map *vars, t_info *info)
{
    read_map(info, vars);
    check_items(info, vars->map);
    // set_map(vars);
    map_border(info, vars->map, vars->height -1, vars->max_width - 1);
    print_map(vars->map);

    // ft_clearr(vars->map);
}