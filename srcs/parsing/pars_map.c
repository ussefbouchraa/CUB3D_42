/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:15:00 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/29 20:26:54 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	map_content(t_info *info, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NWSE0", map[i][j]))
			{
				if (!ft_strchr("01NWSE", map[i][j + 1])
					|| !ft_strchr("01NWSE", map[i][j - 1]))
					free_all(info, map, "Error: Invalid Map element !!!");
				if (!ft_strchr("01NWSE", map[i - 1][j])
					|| !ft_strchr("01NWSE", map[i + 1][j]))
					free_all(info, map, "Error: Invalid Map element !!!");
			}
		}
		i++;
	}
}

void	check_items(t_info *info, char **map)
{
	int	i;
	int	cp;

	cp = 0;
	i = -1;
	while (map[++i])
	{
		if (ft_strchr(map[i], 'N'))
			cp += increment(map[i], 'N');
		if (ft_strchr(map[i], 'W'))
			cp += increment(map[i], 'W');
		if (ft_strchr(map[i], 'S'))
			cp += increment(map[i], 'S');
		if (ft_strchr(map[i], 'E'))
			cp += increment(map[i], 'E');
	}
	if (!cp)
		free_all(info, map, "Error: Missing Player !!");
	if (cp > 1)
		free_all(info, map, "Error: Duplicate player !!");
	if (!valid_char(map))
		free_all(info, map, "Error: Wrong  Element !!");
}

void	fill_map(t_info *info, char **map)
{
	int		start;
	int		m_width;
	int		size;
	char	*spaces;
	int		j;

	j = -1;
	start = info->start;
	m_width = max_width(info->file, start);
	while (info->file[start])
	{
		size = m_width - ft_strlen(info->file[start]);
		if (size != 0)
		{
			spaces = get_spaces(size);
			map[++j] = ft_strjoin(info->file[start], spaces);
			free(spaces);
		}
		else
			map[++j] = ft_strdup(info->file[start]);
		start++;
	}
	map[++j] = NULL;
}

void	read_map(t_info *info, t_map *vars)
{
	vars->height = height_map(info, info->file);
	if (info->items != 6)
	{
		free_clr(info);
		ft_puterr("Error: Wrong Order !!");
	}
	if (!vars->height)
	{
		free_clr(info);
		ft_puterr("Error: Empty Map !!");
	}
	vars->map = malloc(sizeof(char *) * (vars->height + 1));
	if (!vars->map)
	{
		free_clr(info);
		ft_puterr("Error: Allocation Failed !!");
	}
}

void	check_map(t_map *vars, t_info *info)
{
	read_map(info, vars);
	fill_map(info, vars->map);
	check_items(info, vars->map);
	map_content(info, vars->map);
}
