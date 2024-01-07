/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 08:43:54 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/12/31 16:43:34 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ray_caster(t_map *map)
{
	double		angle;
	double		ray_part;
	int			clm;

	clm = 0;
	angle = (map->player->view_angle / 2 * -1) + map->player->rad_current_view;
	ray_part = map->player->view_angle * g_clm / g_width;
	while (angle < map->player->view_angle / 2 + map->player->rad_current_view)
	{
		walls(map, ray_lenght(map, angle), clm);
		angle += ray_part;
		clm += g_clm;
	}
}

void	walls(t_map *map, double len, double x_id)
{
	double		walllen;
	double		y_id;
	int			i;

	i = 0;
	walllen = ((map->b_s / len) * map->pp);
	y_id = (g_height / 2) - (walllen / 2);
	while (i < g_clm && x_id + i < g_width)
	{
		put_c(map, y_id, x_id, i);
		put_wall(map, len, x_id, i);
		put_f(map, len, x_id, i);
		i++;
	}
}

void	put_wall(t_map *map, double len, double x_id, int i)
{
	int		j;
	double	y_id;
	float	walllen;

	walllen = ((map->b_s / len) * map->pp);
	y_id = (g_height / 2) - (walllen / 2);
	j = -1;
	while (++j < walllen)
	{
		if (walllen <= g_height)
			mlx_put_pixel(map->img, x_id + i, y_id + j,
				get_color(map, walllen, j));
		if (walllen > g_height)
		{
			while (i < g_clm && x_id + i < g_width)
			{
				j = -1;
				while (++j < g_height)
					mlx_put_pixel(map->img, x_id + i, j,
						get_color(map, walllen, j - y_id));
				i++;
			}
			return ;
		}
	}
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
