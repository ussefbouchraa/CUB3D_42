/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:51:17 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/12/31 18:46:22 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_cub3d.h"

void	ft_error(t_map *map)
{
	write(2, mlx_strerror(mlx_errno), ft_strlen(mlx_strerror(mlx_errno)));
	free_info(map->info);
	ft_clearr(map->map);
	mlx_close_window(map->mlx);
	mlx_terminate(map->mlx);
	exit(EXIT_FAILURE);
}

int	is_nesw(double sn, double cs, int ver)
{
	if (sn <= 0 && cs >= 0)
	{
		if (ver)
			return ('e');
		return ('n');
	}
	else if (sn <= 0 && cs <= 0)
	{
		if (ver)
			return ('w');
		return ('n');
	}
	else if (sn >= 0 && cs <= 0)
	{
		if (ver)
			return ('w');
		return ('s');
	}
	else if (sn >= 0 && cs >= 0)
	{
		if (ver)
			return ('e');
		return ('s');
	}
	return (-1);
}

void	init_view(t_map *map)
{
	if (map->map[get_y(map->map)][get_x(map->map, get_y(map->map))] == 'N')
		map->player->rad_current_view = (3 * M_PI) / 2;
	if (map->map[get_y(map->map)][get_x(map->map, get_y(map->map))] == 'W')
		map->player->rad_current_view = M_PI;
	if (map->map[get_y(map->map)][get_x(map->map, get_y(map->map))] == 'S')
		map->player->rad_current_view = (M_PI / 2);
	if (map->map[get_y(map->map)][get_x(map->map, get_y(map->map))] == 'E')
		map->player->rad_current_view = 0;
}

uint32_t	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	exit_c(t_map *map)
{
	delete_tex(map);
	mlx_close_window(map->mlx);
	mlx_terminate(map->mlx);
	ft_clearr(map->map);
	free_info(map->info);
	exit(EXIT_SUCCESS);
}
