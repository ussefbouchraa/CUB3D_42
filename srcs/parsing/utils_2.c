/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:02:39 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/25 05:49:16 by ybouchra         ###   ########.fr       */
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
int start_map(char **f_map)
{
    int i;
    int start;
    int len;

    i = 0;
    start = 0;

    while (f_map[i])
    {
        if(!ft_strncmp(f_map[i], "NO ", 3) || !ft_strncmp(f_map[i], "SO ", 3) ||
            !ft_strncmp(f_map[i], "WE ", 3) || !ft_strncmp(f_map[i], "EA ", 3))
                start++;
        else if(!f_map[i][0] || !ft_strncmp(f_map[i], "F ", 2) || !ft_strncmp(f_map[i], "C ", 2))
            start++;
        else
            return(start);
        i++;
    }
    return (start);
}



int max_width( char **f_map)
{
    int i;
    int max;

    i = 0;
    max = ft_strlen(f_map[i]);
    while (f_map[i])
    {
        if (ft_strlen(f_map[i]) > max)
            max = ft_strlen(f_map[i]);
        i++;
    }
    return (max);
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
