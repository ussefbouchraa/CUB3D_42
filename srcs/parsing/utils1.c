/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:14:21 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/28 10:18:03 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	valid_char(char **map)
{
	int	i;
	int	j;

	i = -1;
	if (!map || !map[0])
		return (0);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
			{
				if (map[i][j] != 'N' && map[i][j] != 'W' && map[i][j] != 'S'
					&& map[i][j] != 'E')
					return (0);
			}
		}
	}
	return (1);
}

int	get_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], 'N') || ft_strchr(map[i], 'W')
			|| ft_strchr(map[i], 'S') || ft_strchr(map[i], 'E'))
			return (i);
		i++;
	}
	return (0);
}

int	get_x(char **map, int y)
{
	int	j;

	j = -1;
	while (map[y][++j])
		if (map[y][j] == 'N' || map[y][j] == 'W'
			|| map[y][j] == 'S' || map[y][j] == 'E')
			return (j);
	return (0);
}
