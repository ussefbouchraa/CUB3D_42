/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:14:21 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/27 00:15:01 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../cub3d.h"

// void init_texture(t_mlx *mlx, t_info *info, t_map *map)
// {
//     mlx->mlx = mlx_init();
//     if(!mlx->mlx)
//     {
//         perror("Error");
//         return;
//     }
//     mlx->N_texture = mlx_new_image(mlx, info->NO_txt[1], map->height);
//     mlx->W_texture = mlx_new_image(mlx, info->WE_txt[1], map->height);
//     mlx->S_texture = mlx_new_image(mlx, info->SO_txt[1], map->height);
//     mlx->E_texture = mlx_new_image(mlx, info->EA_txt[1], map->height);
// }