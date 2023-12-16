/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 06:21:59 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/14 14:15:34 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    height_file(char *av, t_info *info)
{
    char *line;

    line = NULL;
    info->fd = open(av, O_RDONLY, 0777);
    if(info->fd == -1)
        ft_puterr("Error: File Not Found");
    line = get_next_line(info->fd);
    while(line)
    {
        info->height++;
        free(line);
        line = get_next_line(info->fd);
    }
    close(info->fd);
}

void    read_file(char *av, t_info *info)
{
    int i;

    i = 0;
    height_file(av, info);
    if(!info->height)
    ft_puterr("Error: Empty File");
    info->fd = open(av, O_RDONLY);
    info->file = malloc(sizeof(char *) * (info->height + 1));
    if(!info->file)
        ft_puterr("Error: Allocation Failed");
    while(info->height > i)
        info->file[i++] = get_next_line(info->fd);
    info->file[i] = NULL;

    close(info->fd);
}

void check_extention(char *av)
{
    // if(!av || !is_exist(av, '.'))
    //     ft_puterr("Error: Invalid Argument !!");
    if(access(av, F_OK  | R_OK ))
         ft_puterr("Error: Invalid Argument !!");
    if(ft_strncmp(ft_strrchr(av, '.'), ".cub", ft_strlen(av)))
        ft_puterr("ERROR : Wrong Extention !!");
}


int main(int ac, char **av)
{
    t_map map;
    t_player player;
    t_info info;

    if(ac == 2)
     {  
        ft_bzero(&info, sizeof(info));
        ft_bzero(&map, sizeof(map));
        ft_bzero(&player, sizeof(player));
        check_extention(av[1]);
        read_file(av[1], &info);
        check_file(&info);
        // check_map(&map);
        
     }
     else
        write(2, "Error: incorrect syntax", 24);
}
