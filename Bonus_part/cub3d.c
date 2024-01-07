/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:24:35 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/12/31 22:04:51 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

void	check_map(t_map *vars, t_info *info)
{
	read_map(info, vars);
	fill_map(info, vars->map);
	check_items(info, vars->map);
	map_border(info, vars->map, vars->height - 1);
	map_content(info, vars->map);
}

void	run_game(t_map *map)
{
	ray_caster(map);
	put_mini_map(map);
	mlx_loop_hook(map->mlx, ft_hook, (void *)map);
	mlx_loop(map->mlx);
	mlx_close_window(map->mlx);
	delete_tex(map);
	mlx_terminate(map->mlx);
	free_all(map->info, map->map, "");
}

void	_parsing(char *av, t_map *map, t_info *info)
{
	check_extention(av);
	read_file(av, info);
	check_file(info, map);
	check_map(map, info);
	init_info(map);
	init_textures(map);
}

int32_t	main(int ac, char **av)
{
	t_map		map;
	t_player	player;
	t_mini_map	mini_map;
	t_info		info;
	t_ray		ray;

	g_width = 1800;
	g_height = 900;
	g_clm = 1;
	if (ac != 2)
		return (write(2, "Error: incorrect syntax", 24), EXIT_FAILURE);
	map.player = &player;
	map.info = &info;
	map.ray = &ray;
	map.mini_map = &mini_map;
	ft_bzero(&info, sizeof(info));
	_parsing(av[1], &map, map.info);
	map.img = mlx_new_image(map.mlx, g_width, g_height);
	if (!map.img || (mlx_image_to_window(map.mlx, map.img, 0, 0) < 0))
		ft_error(&map);
	run_game(&map);
	return (EXIT_SUCCESS);
}
