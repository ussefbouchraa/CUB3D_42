/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:15:00 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/17 13:14:04 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void map_items(t_info *info)
{
    int i;
    int j;

    i = -1;
    if(!info->map || !info->map[0])
        return ;
    while(info->map[++i])
    {
        j = -1;
        while(info->map[i][++j])
        {
            if (info->map[i][j] != '0' && info->map[i][j] != '1' && info->map[i][j] != ' ')
            {
                if (info->map[i][j] != 'N' && info->map[i][j] != 'W' && info->map[i][j] != 'S' && info->map[i][j] != 'E')
                {
                    ft_clearr(info->map);
                    free_items(info);
                    ft_puterr("Error: Invalid Map Items !!");
                }
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

int  height_map(t_info *info)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (info->file[i])
    {
        if (info->file[i][0] && info->file[i][0] == '1' || info->file[i][0] == '0')
            len++;
        i++;
    }
    return(len);
}

int  max_width(t_info *info)
{
    int i;
    int len;

    i = 0;
    len = 0;
    len = ft_strlen(info->map[0]);
    while(info->map[i])
    {
        if(ft_strlen(info->map[i]) > len)
        len = ft_strlen(info->map[i]);
        i++;
    }
    return(len);
}

char *get_spaces(int size)
{
    char *line;
    int i;
    
    i = -1;
    if(size <= 0)
        return(NULL);
    line = malloc(sizeof(char) * (size + 1));
    if(!line)
        return(NULL);
    while(line[++i])
        line[i] = '-';
    line[i] = '\0';
    return(line);
}

void read_map(t_info *info, t_map *vars)
{
    int i;
    int j;

    i = -1;
    j  = 0;
    vars->height = height_map(info);
    if(!vars->height)
    {
        free_items(info);
        ft_puterr("Error: empty Map !");
    }
    info->map = malloc(sizeof(char*) * (vars->height + 1));
    if(!info->map)
        {
            free_items(info);
            perror("Error: ");     
        }
    while (info->file[++i])
    {
        if (info->file[i][0] && (info->file[i][0] == '1' || info->file[i][0] == '0'))
                info->map[j++] = ft_strdup(info->file[i]);
    }
    info->map[j] = NULL;
}

void map_format(t_info *info, t_map *vars)
{
    char *spaces;
    int i;
    int len;
    
    len = 0;
    i = 0;
    vars->max_width = max_width(info);
    vars->map = malloc(sizeof(char*) * (vars->height + 1));
    if(!vars->map)
    {
            ft_clearr(info->map);
            free_items(info);
            perror("Error: ");     
    }
    while(info->map[i])
    {
        len = vars->max_width - ft_strlen(info->map[i]);
        // if (len == 0)
        //    vars->map[i] = ft_strdup(info->map[i]); 
        // else
        // {
            spaces = get_spaces(len);
            printf("-----%s\n", spaces);
            vars->map[i] = ft_strjoin(info->map[i], spaces);
            free(spaces);
        // }
        i++;
    }
    // info->map[i] = NULL;
}

void check_map(t_map *vars, t_info *info)
{
    read_map(info, vars);
    map_items(info);
    map_format(info, vars);
    // map_border(vars, vars->map, vars->height -1);
    // print_map(info->map);
    print_map(vars->map); 
    ft_clearr(info->map);
}