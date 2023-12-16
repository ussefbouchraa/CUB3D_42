/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 07:09:30 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/17 00:06:11 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void check_colors(t_info *info)
{
    
    if(!info->C_colors[0] || !info->F_colors[0] ||
        info->F_colors[2] || info->C_colors[2])
    {
        free_items(info);
        ft_puterr("Error: Wrong Data !!");
    }
    else
    {
        pars_colors(info, info->F_colors[1], info->F_tab);
        pars_colors(info, info->C_colors[1], info->C_tab);
        printf("----%d\n",info->C_tab[0]);
        printf("----%d\n",info->C_tab[1]);
        printf("----%d\n",info->C_tab[2]);
        printf("++++%d\n",info->F_tab[0]);
        printf("++++%d\n",info->F_tab[1]);
        printf("++++%d\n",info->F_tab[2]);
    }
}

void check_texture(t_info *info)
{
    if (!info->NO_txt[0] || !info->WE_txt[0] || !info->SO_txt[0] || !info->EA_txt[0] ||
        info->NO_txt[2] || info->WE_txt[2] || info->SO_txt[2] || info->EA_txt[2])   
    {
        free_items(info);
        ft_puterr("Error: Wrong Data !!");
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

void  valid_items(t_info *info)
{
    int i;
    int cp;

    cp = 0;
    i = -1;
    while (info->file[++i])
    {
        if (!ft_strncmp(info->file[i], "NO ", 3))
            cp++;
        else if (!ft_strncmp(info->file[i], "WE ", 3))
            cp+=2;
        else if (!ft_strncmp(info->file[i], "SO ", 3))
            cp+=3;
        else if (!ft_strncmp(info->file[i], "EA ", 3))
            cp+=4;
        else if (!ft_strncmp(info->file[i], "F ", 2))
            cp+=5;
        else if (!ft_strncmp(info->file[i], "C ", 2))
            cp+=6;
    }
    if (cp != 21)
        ft_puterr("Error: invalid items");
}
 
 void check_file(t_info *info)
 {
    valid_items(info);
    split_items(info);
    check_texture(info);
    check_colors(info);
 }