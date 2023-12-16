/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:12:29 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/12/12 06:42:58 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void put_mini_map(t_map *map, mlx_image_t* img)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '1')
				put_area(x*10 , y*10, 10, 180, img);
			else if (map->map[y][x] == '0' || map->map[y][x] == 'P')
				put_area(x*10, y*10, 10, 60, img);
			// if (map->map[y][x] == 'P')
			//     put_player(x, y, 10, map, img);
			x++;
		}
		y++;
	}
	// mlx_get_monitor_size
}

// void	put_player(int x, int y, int size, t_map *map, mlx_image_t* img)
// {
// 	int x_start;
// 	int y_start;
// 	int x_end;
// 	int y_end;
	
// 	x_start = x*size;
// 	y_start = y*size;
// 	x_end = x_start + size;
// 	y_end = y_start + size;
// 	printf("%d\n", (int)((map->player->x - (int)map->player->x)*10));
// 	while (x_start < x_end)
// 	{
// 		y_start = y*size;
// 		while (y_start < y_end)
// 		{
// 				// printf("%f\n", ((map->player->x - (int)map->player->x)*10));
// 			if (((int)((map->player->x - (int)map->player->x)*10) == x_start - x*size) && ((int)((map->player->y - (int)map->player->y)*10) == y_start - y*size))
// 			{
				
// 				printf("wa3taaaaaaa9 abouda\n");
// 				mlx_put_pixel(img, x_start, y_start, 255);
// 				mlx_put_pixel(img, x_start + 1, y_start, 255);
// 				mlx_put_pixel(img, x_start - 1 , y_start, 255);
// 				mlx_put_pixel(img, x_start, y_start + 1, 255);
// 				mlx_put_pixel(img, x_start, y_start - 1, 255);
// 				mlx_put_pixel(img, x_start + 1, y_start + 1, 255);
// 				mlx_put_pixel(img, x_start - 1, y_start - 1, 255);
// 				mlx_put_pixel(img, x_start + 1, y_start - 1, 255);
// 				mlx_put_pixel(img, x_start - 1, y_start + 1, 255);
// 			}
// 			y_start++;
// 		}
// 		x_start++;
// 	}
// 	return ;
	
	
// }

void put_area(int x_start, int y_start, int size, int color, mlx_image_t* img)
{
	int x_end;
	int y_end;
	int y_tmp;

	x_end = x_start + size;
	y_end = y_start + size;
	y_tmp = y_start;
	while (x_start < x_end)
	{
		y_start = y_tmp;
		while (y_start < y_end)
		{
			mlx_put_pixel(img, x_start, y_start, color);
			y_start++;
		}
		x_start++;
	}
	return ;
}

// void player_p(int *x, int *y)
// {
// 	int i;
// }