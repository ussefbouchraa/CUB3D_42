/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:15:00 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/27 03:21:11 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void map_border(t_info *info, char **map, int height)
{
    int i;
    int j;

    j = -1;
    while (map[0][++j])
    {
        if (map[0][j] != '1' && map[0][j] != ' ')
            free_all(info, map, "Error: Invalid Map border !!");
    }
    j = -1;
    while (map[height][++j])
    {
        if (map[height][j] != '1' && map[height][j] != ' ')
            free_all(info, map, "Error: Invalid Map border !!");
    }
    i = -1;
    while (map[++i])
    {
        if (map[i][0] && map[i][0] != '1'  && map[i][0] != ' ') 
            free_all(info, map, "Error: Invalid Map border !!");
        if (map[i][ft_strlen(map[i]) - 1] != '1' && map[i][ft_strlen(map[i]) - 1] != ' ')
            free_all(info, map, "Error: Invalid Map border !!");
    }
}

void set_map(t_map *vars, char **f_map)
{
    int size;
    char *spaces;
    int i;
    int j;

    i = 0;
    j  = -1;
    vars->max_width = max_width(vars->map);
    while (f_map[i])
    {
            size = vars->max_width - ft_strlen(f_map[i]);
            if(size != 0)
            {
                spaces = get_spaces(size);
                f_map[++j] = ft_strjoin(f_map[i], spaces);
                free(spaces);
            }
            else
                f_map[++j] = ft_strdup(f_map[i]);      
        i++;
    }
    f_map[++j] = NULL;
}
int increment(char *line, char c)
{
    int i;
    int count;
    
    i = 0;
    count = 0;
    while(line[i])
    {
        if(line[i] == c)
        count++;
        i++;
    }
    if(count == 1)
        return (1);
    else
    return(2);    
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
            cp+= increment(map[i], 'N');
        if(ft_strchr(map[i], 'W'))
            cp+= increment(map[i], 'W');
        if(ft_strchr(map[i], 'S'))
            cp+= increment(map[i], 'S');
        if(ft_strchr(map[i], 'E'))
            cp+= increment(map[i], 'E');
    }
    if(!cp)
        free_all(info, map, "Error: Missing Player !!");
    if(cp > 1)
        free_all(info, map, "Error: Duplicate player !!");
    if (!valid_char(map))
        free_all(info, map, "Error: Wrong  Element !!");
}

void fill_map(t_info *info , t_map *vars)
{
    int start;
    int j;

    start = info->start;
    j  = 0;
    while (info->file[start] && info->file[start][0])
    {
        vars->map[j++] = ft_strdup(info->file[start]);
        start++;
    }
    vars->map[j] = NULL;
}

void read_map(t_info *info, t_map *vars)
{
    vars->height = height_map(info, info->file);
    if(info->items != 6)
    {
        free_clr(info);
        ft_puterr("Error: Wrong Order !!");
    }
    if(!vars->height)
    {
        free_clr(info);
        ft_puterr("Error: Empty Map !!");
    }

    vars->map = malloc(sizeof(char*) * (vars->height + 1));
    if(!vars->map)
        {
            free_clr(info);
            ft_puterr("Error: Allocation Failed !!");  
        }
    fill_map(info, vars);
}

void item_border(t_info *info, char **map, int i, int j)
{
    if(!ft_strchr("01NWSE", map[i][j + 1]) || !ft_strchr("01NWSE", map[i][j - 1]))
            free_all(info, map, "Error: Invalid Map element !!!");
    if(!ft_strchr("01NWSE", map[i - 1][j]) || !ft_strchr("01NWSE", map[i + 1][j]))
              free_all(info, map, "Error: Invalid Map element !!!");   
}

void map_content(t_info *info, char **map)
{
    int i;
    int j;
    i = 0;
    while(map[i])
    {
        j = -1;
        while(map[i][++j])
        {
            if(ft_strchr("NWSE0", map[i][j]))
                item_border(info, map, i, j);
        }
        i++;
    }
}

void check_map(t_map *vars, t_info *info)
{
    read_map(info, vars);
    check_items(info, vars->map);
    set_map(vars, vars->map);
    map_border(info, vars->map, vars->height -1);
    map_content(info, vars->map);
}

