/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:02:39 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/28 00:26:46 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int  valid_char(char **map)
{
    int i;
    int j;
    i = -1;
    if(!map || !map[0])
        return (0);
    while(map[++i])
    {
        j = -1;
        while(map[i][++j])
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
            {
                if (map[i][j] != 'N' && map[i][j] != 'W' && map[i][j] != 'S' && map[i][j] != 'E')
                    return(0);
            }
        }
    }
    return(1);
}
int just_spaces(char *map_line)
{
    int i;
    i = 0;
    if (map_line[i] == ' ')
    {
        while (map_line[i] == ' ')
            i++;
        if (map_line[i] == '\0' || map_line[i] == '\n')
            return (1);
    }
    return (0);
}
void  start_map(t_info *info, char **f_map)
{
    int i;

    i = 0;
    while (f_map[i])
    {
        if(!ft_strncmp(f_map[i], "NO ", 3) || !ft_strncmp(f_map[i], "SO ", 3) ||
            !ft_strncmp(f_map[i], "WE ", 3) || !ft_strncmp(f_map[i], "EA ", 3) ||
            !ft_strncmp(f_map[i], "F ", 2) || !ft_strncmp(f_map[i], "C ", 2))
            {
                info->start++;
                info->items++;
            }
        else if(!f_map[i][0] || f_map[i][0] == '\t' || f_map[i][0] == '\n' ||
            f_map[i][0] == '\v' || f_map[i][0] == '\r' || just_spaces(f_map[i]))
            info->start++;
        else
            return;
        i++;
    }
}

int  height_map(t_info *info, char **f_map)
{
    int i;
    int len;
    int start;

    len = 0;
    start_map(info, info->file);
    start = info->start;
    while (f_map[start] && f_map[start][0])
    {
        len++;
        start++;
    }
    return(len);
}

int max_width( char **f_map)
{
    int i;
    int max;

    i = 0;
    if(!f_map || !f_map[i])
        return(0);
    max = ft_strlen(f_map[i]);
    while (f_map[i])
    {
        if (ft_strlen(f_map[i]) > max)
            max = ft_strlen(f_map[i]);
        i++;
    }
    return (max);
}


int get_y(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        if (ft_strchr(map[i], 'N') || ft_strchr(map[i], 'W') || ft_strchr(map[i], 'S') || ft_strchr(map[i], 'E'))
            return (i);
        i++;
    }
    return (0);
}

int get_x(char **map, int y)
{
    int j;
    j = -1;

    while (map[y][++j])
        if (map[y][j] == 'N' || map[y][j] == 'W' || map[y][j] == 'S' || map[y][j] == 'E')
            return (j);
return (0);
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
    while(size > ++i)
        line[i] = ' ';
    line[i] = '\0';
    return(line);
}