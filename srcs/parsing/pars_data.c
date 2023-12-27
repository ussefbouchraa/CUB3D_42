/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:09:06 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/26 22:38:03 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void init_colors(t_info *info, char **arr, int tab[3])
{
    int i;
    
    i = -1;
    while (arr[++i])
    {
        if(is_digit(arr[i]))
            tab[i] = ft_atoi(arr[i]);
        else
        {
            ft_clearr(arr);
            free_clr(info);
            ft_puterr("Error: Invalid Data Colors !!");
        }
    }
    ft_clearr(arr);
    i = -1;
    while (++i < 3)
    {
        if (tab[i] < 0 || tab[i] > 255)
        {
            free_clr(info);
            ft_puterr("Error: Invalid Data Colors !!");
        }
    }
}

void    pars_rgb(t_info *info, char *data_color, int tab[3])
{
    char **arr;

    arr = NULL;
    if (!data_color || ft_strlen(data_color) > 11 || nbr_item(data_color, ',') != 2 )
    {
        free_clr(info);
        ft_puterr("Error: Invalid Data Colors !!");
    }
    arr = ft_split(data_color, ','); 
    if(!arr || !arr[0] || !arr[1] || !arr[2] || arr[3])
    {
        ft_clearr(arr);
        free_clr(info);
        ft_puterr("Error: Invalid Data Colors !!");
    }
    init_colors(info, arr, tab);
}


void    check_paths(t_info *info, char **path)
{
    if (!path[0] || !path[1])
    {
        free_txt(info);
        ft_puterr("Error: Invalid Data Texture !!");
    }
    if( ft_strncmp(ft_strrchr(path[1], '.'), ".png", ft_strlen(path[1])) &&
         !is_exist(path[1], '/'))
            {
                free_txt(info);
                ft_puterr("Error: Invalid Data Texture !!");
            }
}

void    check_colors(t_info *info, t_map *map)
{
    
    if(!info->C_colors[0] || !info->F_colors[0] ||
        info->F_colors[2] || info->C_colors[2])
    {
        free_clr(info);
        ft_puterr("Error: Invalid Data Colors !!");
    }
    else
    {
        pars_rgb(info, info->F_colors[1], map->floor_color);
        pars_rgb(info, info->C_colors[1], map->ceiling_color);
    }
}

void check_texture(t_info *info)
{
    if (!info->NO_txt[0] || !info->WE_txt[0] || !info->SO_txt[0] || !info->EA_txt[0] ||
        info->NO_txt[2] || info->WE_txt[2] || info->SO_txt[2] || info->EA_txt[2])   
    {
        free_txt(info);
        ft_puterr("Error: Invalid Data Texture !!");
    }
    else
    {
        check_paths(info, info->NO_txt);
        check_paths(info, info->WE_txt);
        check_paths(info, info->SO_txt);
        check_paths(info, info->EA_txt);
    }
}

