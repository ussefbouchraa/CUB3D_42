/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:08:44 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/17 06:36:34 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    check_paths(t_info *info, char **path)
{
    if(!path[0] || !path[1])
    {
        free_items(info);
        ft_puterr("Error: Wrong Texture !!");
    }
    if( access(path[1], F_OK | R_OK) ||
        ft_strncmp(ft_strrchr(path[1], '.'), ".png", ft_strlen(path[1])))
            {
                free_items(info);
                ft_puterr("Error: Wrong Texture !!");
            }

}
int digit_arg(char *arr)
{
    int i;

    i = 0;
    if(!arr || !arr[0])
        return(0);
    if(arr[0] == '+')
        i++;
    while(arr[i])
    {
        if(!(arr[i] >= '0' && arr[i] <= '9'))
            return(0);
    i++;
    }
    return(1); 
}

void init_colors(t_info *info, char **arr, int tab[3])
{
    int i;
    
    i = -1;
    while (arr[++i])
    {
        if(digit_arg(arr[i]))
            tab[i] = ft_atoi(arr[i]);
        else
        {
            free_items(info);
            ft_puterr("Error: Wrong data_color !!");
        }
    }
    ft_clearr(arr);
    i = -1;
    while (++i < 3)
    {
        if (tab[i] < 0 || tab[i] > 255)
        {
            free_items(info);
            ft_puterr("Error: Wrong Data 2!!");
        }
    }
}

void    pars_colors(t_info *info, char *data_color, int tab[3])
{
    char **arr;

    arr = NULL;
    if (!data_color || ft_strlen(data_color) > 11 || nbr_item(data_color, ',') != 2 )
    {
        free_items(info);
        ft_puterr("Error: Wrong data_color !!");
    }
    arr = ft_split(data_color, ','); 
    if(!arr || !arr[0] || !arr[1]|| !arr[2] || arr[3])
    {
        free_items(info);
        ft_puterr("Error: Wrong data_color !!");
    }
    init_colors(info, arr, tab);
}

void free_items(t_info *info)
{
    ft_clearr(info->NO_txt);
    ft_clearr(info->WE_txt);
    ft_clearr(info->SO_txt);
    ft_clearr(info->EA_txt);
    ft_clearr(info->F_colors);
    ft_clearr(info->C_colors);
    info->NO_txt = NULL;
    info->WE_txt = NULL;
    info->SO_txt = NULL;
    info->EA_txt = NULL;
    info->C_colors = NULL;
    info->F_colors = NULL;
}