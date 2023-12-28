/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:54:48 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/28 09:40:53 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	split_items(t_info *info)
{
	int	i;

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

int	is_dup(char *itm, char **file)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (file[i])
	{
		if (!ft_strncmp(file[i], itm, 2))
			count++;
		i++;
	}
	if (count == 1)
		return (0);
	else
		return (1);
}

void	valid_items(char **file)
{
	int	i;
	int	cp;

	cp = 0;
	i = -1;
	while (file[++i])
	{
		if (!ft_strncmp(file[i], "NO ", 3) && !is_dup("NO", file))
			cp++;
		else if (!ft_strncmp(file[i], "WE ", 3) && !is_dup("WE", file))
			cp++;
		else if (!ft_strncmp(file[i], "SO ", 3) && !is_dup("SO", file))
			cp++;
		else if (!ft_strncmp(file[i], "EA ", 3) && !is_dup("EA", file))
			cp++;
		else if (!ft_strncmp(file[i], "F ", 2) && !is_dup("F ", file))
			cp++;
		else if (!ft_strncmp(file[i], "C ", 2) && !is_dup("C ", file))
			cp++;
	}
	if (cp != 6)
	{
		ft_clearr(file);
		ft_puterr("Error: Invalid Data File !!");
	}
}

void	check_file(t_info *info, t_map *map)
{
	valid_items(info->file);
	split_items(info);
	check_texture(info);
	check_colors(info, map);
}
