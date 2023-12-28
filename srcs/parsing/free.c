/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:15:30 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/28 09:42:28 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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
	ft_clearr(info->NO_txt);
	ft_clearr(info->WE_txt);
	ft_clearr(info->SO_txt);
	ft_clearr(info->EA_txt);
}

void	free_clr(t_info *info)
{
	free_txt(info);
	ft_clearr(info->F_colors);
	ft_clearr(info->C_colors);
}

void	free_all(t_info *info, char **map, char *msg)
{
	ft_clearr(map);
	free_clr(info);
	ft_puterr(msg);
}
