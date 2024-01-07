/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:14:21 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/31 17:59:47 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	valid_char(char **map)
{
	int	i;
	int	j;

	i = -1;
	if (!map || !map[0])
		return (0);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
			{
				if (map[i][j] != 'N' && map[i][j] != 'W' && map[i][j] != 'S'
					&& map[i][j] != 'E')
					return (0);
			}
		}
	}
	return (1);
}

int	get_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], 'N') || ft_strchr(map[i], 'W')
			|| ft_strchr(map[i], 'S') || ft_strchr(map[i], 'E'))
			return (i);
		i++;
	}
	return (0);
}

int	get_x(char **map, int y)
{
	int	j;

	j = -1;
	while (map[y][++j])
		if (map[y][j] == 'N' || map[y][j] == 'W'
			|| map[y][j] == 'S' || map[y][j] == 'E')
			return (j);
	return (0);
}

void	init_info(t_map *map)
{
	map->mlx = mlx_init(g_width, g_height, "cub3d", true);
	if (!map->mlx)
		ft_error(map);
	map->b_s = 128;
	map->player->mv_speed = 30;
	map->player->rt_speed = 3 * (M_PI / 180);
	map->player->view_angle = 60 * (M_PI / 180);
	map->player->x = (get_x(map->map,
				get_y(map->map)) * map->b_s) + (map->b_s / 2);
	map->player->y = (get_y(map->map) * map->b_s) + (map->b_s / 2);
	map->pp = (g_width / 2) / tan(map->player->view_angle / 2);
	if (map->map[get_y(map->map)][get_x(map->map, get_y(map->map))] == 'N')
		map->player->rad_current_view = (3 * M_PI) / 2;
	if (map->map[get_y(map->map)][get_x(map->map, get_y(map->map))] == 'W')
		map->player->rad_current_view = M_PI;
	if (map->map[get_y(map->map)][get_x(map->map, get_y(map->map))] == 'S')
		map->player->rad_current_view = (M_PI / 2);
	if (map->map[get_y(map->map)][get_x(map->map, get_y(map->map))] == 'E')
		map->player->rad_current_view = 0;
	map->map[get_y(map->map)][get_x(map->map, get_y(map->map))] = '0';
}
