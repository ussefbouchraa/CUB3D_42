/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:24:35 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/12/12 06:42:58 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#define WIDTH 1800
#define HEIGHT 900

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void ft_hook(void* param)
{
	const t_map* map = param;
	// printf("WIDTH: %d | HEIGHT: %d\n", map->mlx->width, map->mlx->height);
	
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
		printf("up\n");
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		printf("down\n");
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		printf("left\n");
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		printf("right\n");
		
}

// void	player_mv(t_map *map)
// {
// 	map->player->x += map->player->mv_speed*map->player->mv;
// 	map->player->y += map->player->mv_speed*map->player->mv;
// }

int32_t	main(void)
{
	t_map map;
	t_player player;
	
	char **ma;

	ma = malloc(sizeof(char *)*15);
	ma[0] =  ft_strdup("      11111 111   11111111  11111");
	ma[1] =  ft_strdup("      100011101111100000011110001");
	ma[2] =  ft_strdup("   111100000111000000000111111111");
	ma[3] =  ft_strdup("   1001000000000000000001");
	ma[4] =  ft_strdup("   1111111110110000011101111");
	ma[5] =  ft_strdup("      10000001100000111011111111");
	ma[6] =  ft_strdup("111111011111111101110000001000111");
	ma[7] =  ft_strdup("111000011111111011101010011100001");
	ma[8] =  ft_strdup("111111000011010101110000001000111");
	ma[9] =  ft_strdup("      10000000000001100000011101");
	ma[10] = ft_strdup("   11110000000000001101010010001");
	ma[11] = ft_strdup("   11000001110101011111011110P01");
	ma[12] = ft_strdup("   11110111011101000111101000001");
	ma[13] = ft_strdup("     1111 111 1111111  111111111");
	ma[14] = NULL;
	map.block_size = 50;
	map.map = ma;
	map.player = &player;
	map.map_height = 34;
	map.map_width = 14;
	player.score = 0;
	player.mv_speed = 3;
	player.rt_speed = 3 * (M_PI / 180);
	player.x = 30 * map.block_size;
	player.y = 12 * map.block_size;
	player.rad_current_view = M_PI;
	mlx_get_monitor_size(0, &map.max_width, &map.max_height);
	printf("%d\n", map.max_height);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!mlx)
		ft_error();
	map.mlx = mlx;
	mlx_image_t* img = mlx_new_image(mlx, 1800, 900);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	put_mini_map(&map, img);
	mlx_loop_hook(mlx, ft_hook, (void *)&map);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	// printf("%f\n", player.rad_current_view);
	return (EXIT_SUCCESS);
}
