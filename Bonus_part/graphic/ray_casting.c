/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:21:16 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/12/31 17:20:33 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_cub3d.h"

void	delta(t_map *map, double cs, double sn, char c)
{
	if (c == 'v')
	{
		if (cs < 0)
			map->ray->d_x = map->ray->d_x * -1;
		if (sn < 0 && map->ray->d_y > 0)
			map->ray->d_y = map->ray->d_y * -1;
		if (sn > 0 && map->ray->d_y < 0)
			map->ray->d_y = map->ray->d_y * -1;
	}
	else
	{
		if (sn < 0)
			map->ray->d_y = map->ray->d_y * -1;
		if (cs < 0 && map->ray->d_x > 0)
			map->ray->d_x = map->ray->d_x * -1;
		if (cs > 0 && map->ray->d_x < 0)
			map->ray->d_x = map->ray->d_x * -1;
	}
}

void	adjust(int *x, int *y, double cs, double sn)
{
	if (sn <= 0 && cs >= 0)
	{
		*x = 1;
		*y = -1;
	}
	else if (sn <= 0 && cs <= 0)
	{
		*x = -1;
		*y = -1;
	}
	else if (sn >= 0 && cs <= 0)
	{
		*x = -1;
		*y = 1;
	}
	else if (sn >= 0 && cs >= 0)
	{
		*x = 1;
		*y = 1;
	}
}

double	horizontal_ray_len(t_map *map, double angle, double cs, double sn)
{
	int		x;
	int		y;

	adjust(&x, &y, cs, sn);
	map->ray->h_ya = map->player->y - ((int)map->player->y % map->b_s);
	if (sn > 0)
		map->ray->h_ya += map->b_s;
	map->ray->h_xa = map->player->x
		+ ((map->ray->h_ya - map->player->y) / tan(angle));
	if (is_wall(map, map->ray->h_xa, map->ray->h_ya + y))
		return (sqrt(pow(map->player->x - map->ray->h_xa, 2)
				+ pow(map->player->y - map->ray->h_ya, 2)));
	map->ray->d_x = map->b_s / tan(angle);
	map->ray->d_y = map->b_s;
	delta(map, cs, sn, 'h');
	while (true)
	{
		map->ray->h_ya += map->ray->d_y;
		map->ray->h_xa += map->ray->d_x;
		if (is_wall(map, map->ray->h_xa, map->ray->h_ya + y))
			return (sqrt(pow(map->player->x - map->ray->h_xa, 2)
					+ pow(map->player->y - map->ray->h_ya, 2)));
	}
}

double	vertical_ray_len(t_map *map, double angle, double cs, double sn)
{
	int		x;
	int		y;

	adjust(&x, &y, cs, sn);
	map->ray->v_xa = map->player->x - ((int)map->player->x % map->b_s);
	if (cs > 0)
		map->ray->v_xa += map->b_s;
	map->ray->v_ya = map->player->y
		+ ((map->ray->v_xa - map->player->x) * tan(angle));
	if (is_wall(map, map->ray->v_xa + x, map->ray->v_ya))
		return (sqrt(pow(map->player->x - map->ray->v_xa, 2)
				+ pow(map->player->y - map->ray->v_ya, 2)));
	map->ray->d_x = map->b_s;
	map->ray->d_y = map->b_s * tan(angle);
	delta(map, cs, sn, 'v');
	while (true)
	{
		map->ray->v_ya += map->ray->d_y;
		map->ray->v_xa += map->ray->d_x;
		if (is_wall(map, map->ray->v_xa + x, map->ray->v_ya))
			return (sqrt(pow(map->player->x - map->ray->v_xa, 2)
					+ pow(map->player->y - map->ray->v_ya, 2)));
	}
}

double	ray_lenght(t_map *map, double angle)
{
	double	horizontal;
	double	vertical;
	double	cs;
	double	sn;

	sn = sin(angle);
	cs = cos(angle);
	map->ray->cs = cs;
	map->ray->sn = sn;
	horizontal = horizontal_ray_len(map, angle, cs, sn)
		* cos(map->player->rad_current_view - angle);
	vertical = vertical_ray_len(map, angle, cs, sn)
		* cos(map->player->rad_current_view - angle);
	if ((long)horizontal == (long)vertical)
		return (horizontal);
	if (horizontal > vertical)
	{
		map->ray->ver = 1;
		map->ray->nswe = is_nesw(sn, cs, 1);
		return (vertical);
	}
	map->ray->ver = 0;
	map->ray->nswe = is_nesw(sn, cs, 0);
	return (horizontal);
}
