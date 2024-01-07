/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:24:35 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/12/31 18:24:25 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_hook(void *param)
{
	t_map	*map;

	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
	{
		delete_tex(map);
		mlx_close_window(map->mlx);
		mlx_terminate(map->mlx);
		ft_clearr(map->map);
		free_info(map->info);
		exit(EXIT_SUCCESS);
	}
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
}

void	window_update(t_map *map)
{
	g_width = map->mlx->width;
	g_height = map->mlx->height;
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, g_width, g_height);
	if (!map->img || (mlx_image_to_window(map->mlx, map->img, 0, 0) < 0))
		ft_error(map);
	player_update(map, 0, 0);
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
}

void	init_textures(t_map *map)
{
	map->texture->s_texture = mlx_load_png(map->info->so_txt[1]);
	if (!map->texture->s_texture)
		ft_error(map);
	map->texture->e_texture = mlx_load_png(map->info->ea_txt[1]);
	if (!map->texture->e_texture)
		ft_error(map);
	map->texture->w_texture = mlx_load_png(map->info->we_txt[1]);
	if (!map->texture->w_texture)
		ft_error(map);
	map->texture->n_texture = mlx_load_png(map->info->no_txt[1]);
	if (!map->texture->n_texture)
		ft_error(map);
	if (map->texture->e_texture->height != 128
		|| map->texture->e_texture->height != 128
		|| map->texture->e_texture->height != 128
		|| map->texture->e_texture->height != 128
		|| map->texture->e_texture->width != 128
		|| map->texture->e_texture->width != 128
		|| map->texture->e_texture->width != 128
		|| map->texture->e_texture->width != 128)
	{
		mlx_errno = MLX_INVPNG;
		ft_error(map);
	}
}
