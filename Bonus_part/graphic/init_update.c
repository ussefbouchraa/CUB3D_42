/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:24:35 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/12/31 18:44:30 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_cub3d.h"

void	ft_hook(void *param)
{
	t_map	*map;

	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		exit_c(map);
	if (mlx_is_key_down(map->mlx, 265) || mlx_is_key_down(map->mlx, 87))
		player_update(map, 1, 0);
	if (mlx_is_key_down(map->mlx, 264) || mlx_is_key_down(map->mlx, 83))
		player_update(map, -1, 0);
	if (mlx_is_key_down(map->mlx, 263) || mlx_is_key_down(map->mlx, 65))
		player_update(map, 0, -1);
	if (mlx_is_key_down(map->mlx, 262) || mlx_is_key_down(map->mlx, 68))
		player_update(map, 0, 1);
	if (map->mlx->width != g_width || map->mlx->height != g_height)
		window_update(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_Q))
		ft_speed(map, 'q');
	if (mlx_is_key_down(map->mlx, MLX_KEY_R))
		ft_speed(map, 'r');
	if (mlx_is_key_down(map->mlx, MLX_KEY_V))
		ft_speed(map, 'v');
	if (mlx_is_key_down(map->mlx, MLX_KEY_P))
		ft_speed(map, 'p');
}

void	window_update(t_map *map)
{
	if (map->mlx->width <= map->mini_map->map_width
		|| map->mlx->height <= map->mini_map->map_height)
		return ;
	g_width = map->mlx->width;
	g_height = map->mlx->height;
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, g_width, g_height);
	if (!map->img || (mlx_image_to_window(map->mlx, map->img, 0, 0) < 0))
		ft_error(map);
	player_update(map, 0, 0);
}

void	ft_speed(t_map *map, char c)
{
	if (map->player->mv_speed >= 90 && c == 'q')
		map->player->mv_speed = 10;
	else if (c == 's')
		map->player->mv_speed += 15;
	if (map->player->rt_speed >= 5 * (M_PI / 180) && c == 'r')
		map->player->rt_speed = 1 * (M_PI / 180);
	else if (c == 'r')
		map->player->rt_speed += 0.5 * (M_PI / 180);
	if (map->player->view_angle >= 90 * (M_PI / 180) && c == 'v')
	{
		map->player->view_angle = 60 * (M_PI / 180);
		map->pp = (g_width / 2) / tan(map->player->view_angle / 2);
	}
	else if (c == 'v')
	{
		map->player->view_angle += 5 * (M_PI / 180);
		map->pp = (g_width / 2) / tan(map->player->view_angle / 2);
	}
	if (g_clm >= 20 && c == 'p')
		g_clm = 1;
	else if (c == 'p')
		g_clm += 1;
	player_update(map, 0, 0);
	usleep(100000);
}

void	player_update(t_map *map, int mv, int rt)
{
	double	x;
	double	y;
	int		x_a;
	int		y_a;
	int		i;

	i = 0;
	x = cos(map->player->rad_current_view) * mv * map->player->mv_speed;
	y = sin(map->player->rad_current_view) * mv * map->player->mv_speed;
	x_a = (cos(map->player->rad_current_view) * mv * 100) + map->player->x + x;
	y_a = (sin(map->player->rad_current_view) * mv * 100) + map->player->y + y;
	map->player->rad_current_view += map->player->rt_speed * rt;
	while (i < map->player->mv_speed)
	{
		x = cos(map->player->rad_current_view) * mv * i;
		y = sin(map->player->rad_current_view) * mv * i;
		if (is_wall(map, x + x_a, y + y_a) == 1)
			return ;
		i++;
	}
	map->player->x += x;
	map->player->y += y;
	ray_caster(map);
	put_mini_map(map);
}

void	init_textures(t_map *map)
{
	map->s_texture = mlx_load_png(map->info->so_txt[1]);
	if (!map->s_texture)
		ft_error(map);
	map->e_texture = mlx_load_png(map->info->ea_txt[1]);
	if (!map->e_texture)
		ft_error(map);
	map->w_texture = mlx_load_png(map->info->we_txt[1]);
	if (!map->w_texture)
		ft_error(map);
	map->n_texture = mlx_load_png(map->info->no_txt[1]);
	if (!map->n_texture)
		ft_error(map);
	if (map->e_texture->height != 512
		|| map->e_texture->height != 512
		|| map->e_texture->height != 512
		|| map->e_texture->height != 512
		|| map->e_texture->width != 512
		|| map->e_texture->width != 512
		|| map->e_texture->width != 512
		|| map->e_texture->width != 512)
	{
		mlx_errno = MLX_INVPNG;
		ft_error(map);
	}
}
