/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:21:16 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/12/31 15:42:44 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

uint32_t	get_color(t_map *map, double walllen, int j)
{
	int			x_pos;
	int			y_pos;
	int			tmp;

	y_pos = j * map->b_s / walllen;
	if (map->ray->ver == 1)
		x_pos = (int)map->ray->v_ya % map->b_s;
	else
		x_pos = (int)map->ray->h_xa % map->b_s;
	tmp = ((map->b_s * y_pos) + x_pos) * 4;
	return (pixel_color(map, tmp));
}

uint32_t	pixel_color(t_map *map, int pos)
{
	uint32_t	color;

	if (map->ray->nswe == 'e')
		color = get_rgba(map->texture->e_texture->pixels[pos + 0],
				map->texture->e_texture->pixels[pos + 1],
				map->texture->e_texture->pixels[pos + 2],
				map->texture->e_texture->pixels[pos + 3]);
	else if (map->ray->nswe == 'w')
		color = get_rgba(map->texture->w_texture->pixels[pos + 0],
				map->texture->w_texture->pixels[pos + 1],
				map->texture->w_texture->pixels[pos + 2],
				map->texture->w_texture->pixels[pos + 3]);
	else if (map->ray->nswe == 'n')
		color = get_rgba(map->texture->n_texture->pixels[pos + 0],
				map->texture->n_texture->pixels[pos + 1],
				map->texture->n_texture->pixels[pos + 2],
				map->texture->n_texture->pixels[pos + 3]);
	else
		color = get_rgba(map->texture->s_texture->pixels[pos + 0],
				map->texture->s_texture->pixels[pos + 1],
				map->texture->s_texture->pixels[pos + 2],
				map->texture->s_texture->pixels[pos + 3]);
	return (color);
}

void	put_c(t_map *map, double y_id, double x_id, int i)
{
	int	j;

	j = 0;
	while (j < y_id)
	{
		mlx_put_pixel(map->img, x_id + i, 0 + j, get_rgba(map->ceiling_color[0],
				map->ceiling_color[1], map->ceiling_color[2], 200));
		j++;
	}
}

void	put_f(t_map *map, double len, double x_id, int i)
{
	int		j;
	double	y_id;
	float	walllen;

	walllen = ((map->b_s / len) * map->pp);
	y_id = (g_height / 2) - (walllen / 2);
	j = 0;
	while (j < y_id)
	{
		mlx_put_pixel(map->img, x_id + i, y_id + walllen + j, get_rgba
			(map->floor_color[0], map->floor_color[1],
				map->floor_color[2], 200));
		j++;
	}
}
