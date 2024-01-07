/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:12:29 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/12/31 16:42:28 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_cub3d.h"

void	put_mini_map(t_map *map)
{
	double	x;
	double	y;
	double	x_p;
	double	y_p;

	x = -1;
	while (++x < map->mini_map->map_width)
	{
		y = -1;
		while (++y < map->mini_map->map_height)
		{
			x_p = map->player->x - (map->b_s * (map->mini_map->map_width
						/ 2 - x) / map->mini_map->mini_block);
			y_p = map->player->y - (map->b_s * (map->mini_map->map_height
						/ 2 - y) / map->mini_map->mini_block);
			if (is_wall(map, x_p, y_p) == 1)
				mlx_put_pixel(map->img, x, y, 255);
			else if (is_wall(map, x_p, y_p) == 0)
				mlx_put_pixel(map->img, x, y, 80);
			else
				mlx_put_pixel(map->img, x, y, 0);
		}
	}
	put_der(map);
}

int	is_wall(t_map *map, double x, double y)
{
	int	j;
	int	i;

	j = x / map->b_s;
	i = y / map->b_s;
	if (i < 0 || j < 0 || i >= map->height
		|| j >= (int)ft_strlen(map->map[i]))
		return (1);
	if (map->map[i][j] == '1')
		return (1);
	else if (map->map[i][j] == '0')
		return (0);
	return (1);
}

void	put_der(t_map *map)
{
	double	x;
	double	y;
	int		i;

	i = 1;
	x = map->mini_map->map_width / 2;
	y = map->mini_map->map_height / 2;
	while (i < 11)
	{
		x += cos(map->player->rad_current_view);
		y += sin(map->player->rad_current_view);
		i++;
		mlx_put_pixel(map->img, x, y, 255);
	}
	put_area(map->mini_map->map_width / 2 - 2,
		map->mini_map->map_height / 2 - 2, 5, map->img);
}

void	put_area(int x_start, int y_start, int size, mlx_image_t *img)
{
	int		x_end;
	int		y_end;
	int		y_tmp;

	x_end = x_start + size;
	y_end = y_start + size;
	y_tmp = y_start;
	while (x_start < x_end)
	{
		y_start = y_tmp;
		while (y_start < y_end)
		{
			mlx_put_pixel(img, x_start, y_start, 255);
			y_start++;
		}
		x_start++;
	}
	return ;
}
