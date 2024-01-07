/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:15:30 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/31 13:52:11 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
	write(2, "\n", 2);
	exit(0);
}

void	ft_clearr(char **arr)
{
	int	i;

	i = -1;
	if (!arr || !arr[0])
		return ;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	arr = NULL;
}

void	free_txt(t_info *info)
{
	ft_clearr(info->no_txt);
	ft_clearr(info->we_txt);
	ft_clearr(info->so_txt);
	ft_clearr(info->ea_txt);
}

void	free_info(t_info *info)
{
	free_txt(info);
	ft_clearr(info->f_colors);
	ft_clearr(info->c_colors);
}

void	free_all(t_info *info, char **map, char *msg)
{
	free_info(info);
	ft_clearr(map);
	ft_puterr(msg);
}
