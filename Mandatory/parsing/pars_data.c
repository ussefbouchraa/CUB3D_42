/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:09:06 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/31 13:52:11 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_colors(t_info *info, char **arr, int tab[3])
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		if (is_digit(arr[i]))
			tab[i] = ft_atoi(arr[i]);
		else
		{
			ft_clearr(arr);
			free_info(info);
			ft_puterr("Error: Invalid Data Colors !!");
		}
	}
	ft_clearr(arr);
	i = -1;
	while (++i < 3)
	{
		if (tab[i] < 0 || tab[i] > 255)
		{
			free_info(info);
			ft_puterr("Error: Invalid Data Colors !!");
		}
	}
}

void	pars_rgb(t_info *info, char *data_color, int tab[3])
{
	char	**arr;

	arr = NULL;
	if (!data_color || ft_strlen(data_color) > 11
		|| nbr_item(data_color, ',') != 2)
	{
		free_info(info);
		ft_puterr("Error: Invalid Data Colors ! !");
	}
	arr = ft_split(data_color, ',');
	if (!arr || !arr[0] || !arr[1] || !arr[2] || arr[3])
	{
		ft_clearr(arr);
		free_info(info);
		ft_puterr("Error: Invalid Data Colors !!");
	}
	init_colors(info, arr, tab);
}

void	check_paths(t_info *info, char **path)
{
	if (!path[0] || !path[1])
	{
		free_txt(info);
		ft_puterr("Error: Invalid Data Texture !!");
	}
	if (ft_strncmp(ft_strrchr(path[1], '.'), ".png", 4))
	{
		free_txt(info);
		ft_puterr("Error: Invalid Data Texture !!");
	}
}

void	check_colors(t_info *info, t_map *map)
{
	if (!info->c_colors[0] || !info->f_colors[0]
		|| info->f_colors[2] || info->c_colors[2])
	{
		free_info(info);
		ft_puterr("Error: Invalid Data Colors !!");
	}
	else
	{
		pars_rgb(info, info->f_colors[1], map->floor_color);
		pars_rgb(info, info->c_colors[1], map->ceiling_color);
	}
}

void	check_texture(t_info *info)
{
	if (!info->no_txt[0] || !info->we_txt[0]
		|| !info->so_txt[0] || !info->ea_txt[0])
	{
		free_txt(info);
		ft_puterr("Error: Invalid Data Texture !!");
	}
	else if (info->no_txt[2] || info->we_txt[2]
		|| info->so_txt[2] || info->ea_txt[2])
	{
		free_txt(info);
		ft_puterr("Error: Invalid Data Texture !!");
	}
	else
	{
		check_paths(info, info->no_txt);
		check_paths(info, info->we_txt);
		check_paths(info, info->so_txt);
		check_paths(info, info->ea_txt);
	}
}
