/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:44:45 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/25 04:44:28 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void check_colors(t_info *info)
{
    
    if(!info->C_colors[0] || !info->F_colors[0] ||
        info->F_colors[2] || info->C_colors[2])
    {
        free_items(info);
        ft_puterr("Error: Invalid Data !!");
    }
    else
    {
        pars_rgb(info, info->F_colors[1], info->F_tab);
        pars_rgb(info, info->C_colors[1], info->C_tab);
    }
}

void check_texture(t_info *info)
{
    if (!info->NO_txt[0] || !info->WE_txt[0] || !info->SO_txt[0] || !info->EA_txt[0] ||
        info->NO_txt[2] || info->WE_txt[2] || info->SO_txt[2] || info->EA_txt[2])   
    {
        free_items(info);
        ft_puterr("Error: Invalid Data !!");
    }
    else
    {
        check_paths(info, info->NO_txt);
        check_paths(info, info->WE_txt);
        check_paths(info, info->SO_txt);
        check_paths(info, info->EA_txt);
    }
}

void    split_items(t_info *info)
{
    int i;

    i = -1;
    while (info->file[++i])
    {
        if (!ft_strncmp(info->file[i], "NO ", 3))
            info->NO_txt = ft_split(info->file[i], ' ');
        else if (!ft_strncmp(info->file[i], "WE ", 3))
            info->WE_txt = ft_split(info->file[i], ' ');
        else if (!ft_strncmp(info->file[i], "SO ", 3))
            info->SO_txt = ft_split(info->file[i], ' ');
        else if (!ft_strncmp(info->file[i], "EA ", 3))
            info->EA_txt = ft_split(info->file[i], ' ');
        else if (!ft_strncmp(info->file[i], "F ", 2))
            info->F_colors = ft_split(info->file[i], ' ');
        else if (!ft_strncmp(info->file[i], "C ", 2))
            info->C_colors = ft_split(info->file[i], ' ');
    }
}

int is_dup(char *itm, char **file)
{
    int i;
    int count;

    count = 0;
    i = 0;

    while(file[i])
    {
        if(!ft_strncmp(file[i], itm, 2))
            count++;
        i++;
    }
    if(count == 1)
        return(0);
    else
        return(1);
}
void  valid_items(t_info *info)
{
    int i;
    int cp;

    cp = 0;
    i = -1;
    while (info->file[++i])
    {
        if (!ft_strncmp(info->file[i], "NO ", 3) && !is_dup("NO", info->file))
            cp++;
        else if (!ft_strncmp(info->file[i], "WE ", 3) && !is_dup("WE", info->file))
            cp++;
        else if (!ft_strncmp(info->file[i], "SO ", 3) && !is_dup("SO", info->file))
           cp++;
        else if (!ft_strncmp(info->file[i], "EA ", 3) && !is_dup("EA", info->file))
            cp++;
        else if (!ft_strncmp(info->file[i], "F ", 2) && !is_dup("F ", info->file))
            cp++;
        else if (!ft_strncmp(info->file[i], "C ", 2) && !is_dup("C ", info->file))
            cp++;
    }
    if (cp != 6)
    {
        ft_clearr(info->file);
        ft_puterr("Error: Invalid Data !!");
    }
}

 void check_file(t_info *info, t_map *map)
 {
    valid_items(info);
    split_items(info);
    check_texture(info);
    check_colors(info);
    check_map(map, info);
 }