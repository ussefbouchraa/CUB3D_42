/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:02:39 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/29 20:31:01 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	start_map(t_info *info, char **f_map)
{
	int	i;

	i = 0;
	while (f_map[i])
	{
		if (!ft_strncmp(f_map[i], "NO ", 3) || !ft_strncmp(f_map[i], "SO ", 3)
			|| !ft_strncmp(f_map[i], "WE ", 3)
			|| !ft_strncmp(f_map[i], "EA ", 3))
		{
			info->start++;
			info->items++;
		}
		else if (!ft_strncmp(f_map[i], "F ", 2)
			|| !ft_strncmp(f_map[i], "C ", 2))
		{
			info->start++;
			info->items++;
		}
		else if (!f_map[i][0] || f_map[i][0] == '\t' || f_map[i][0] == '\n'
				|| f_map[i][0] == '\r' || just_spaces(f_map[i]))
			info->start++;
		else
			return ;
		i++;
	}
}

int	height_map(t_info *info, char **f_map)
{
	int	len;
	int	start;

	len = 0;
	start_map(info, info->file);
	start = info->start;
	while (f_map[start])
	{
		len++;
		start++;
	}
	return (len);
}

int	max_width(char **f_map, int start)
{
	size_t	max;

	if (!f_map)
		return (0);
	max = ft_strlen(f_map[start]);
	while (f_map[start])
	{
		if (ft_strlen(f_map[start]) > max)
			max = ft_strlen(f_map[start]);
		start++;
	}
	return (max);
}

char	*get_spaces(int size)
{
	char	*line;
	int		i;

	i = -1;
	if (size <= 0)
		return (NULL);
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	while (size > ++i)
		line[i] = ' ';
	line[i] = '\0';
	return (line);
}

int	just_spaces(char *map_line)
{
	int	i;

	i = 0;
	if (map_line[i] == ' ')
	{
		while (map_line[i] == ' ')
			i++;
		if (map_line[i] == '\0' || map_line[i] == '\n')
			return (1);
	}
	return (0);
}
