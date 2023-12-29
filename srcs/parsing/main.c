/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:41:23 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/29 20:27:54 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	height_file(char *av, t_info *info)
{
	char	*line;

	line = NULL;
	info->fd = open(av, O_RDONLY, 0777);
	if (info->fd == -1)
		ft_puterr("Error: File Not Found");
	line = get_next_line(info->fd);
	while (line)
	{
		info->height++;
		free(line);
		line = get_next_line(info->fd);
	}
	close(info->fd);
}

void	read_file(char *av, t_info *info)
{
	int	i;

	i = 0;
	height_file(av, info);
	if (!info->height)
		ft_puterr("Error: Empty File");
	info->fd = open(av, O_RDONLY);
	info->file = malloc(sizeof(char *) * (info->height + 1));
	if (!info->file)
		ft_puterr("Error: allocation failed !!");
	while (info->height > i)
		info->file[i++] = get_next_line(info->fd);
	info->file[i] = NULL;
	close(info->fd);
}

void	check_extention(char *av)
{
	if (!av || !is_exist(av, '.'))
		ft_puterr("Error: Invalid Argument !!");
	if (ft_strncmp(ft_strrchr(av, '.'), ".cub", ft_strlen(av)))
		ft_puterr("ERROR : Wrong Extention !!");
}

void	init_info(t_info *info, t_map *vars, t_player *player)
{
	player->y = get_y(vars->map);
	player->x = get_x(vars->map, player->y);
	if (vars->map[player->y][player->x] == 'N')
		player->rad_current_view = (3 * M_PI) / 2;
	if (vars->map[player->y][player->x] == 'W')
		player->rad_current_view = M_PI;
	if (vars->map[player->y][player->x] == 'S')
		player->rad_current_view = (M_PI / 2);
	if (vars->map[player->y][player->x] == 'E')
		player->rad_current_view = 0;
	vars->map[player->y][player->x] = '0';
}

int	main(int ac, char **av)
{
	t_player	player;
	t_map		map;
	t_info		info;

	if (ac == 2)
	{
		ft_bzero(&info, sizeof(info));
		check_extention(av[1]);
		read_file(av[1], &info);
		check_file(&info, &map);
		check_map(&map, &info);
		init_info(&info, &map, &player);
		free_clr(&info);
		ft_clearr(map.map);
	}
	else
		write(2, "Error: incorrect syntax !!", 24);
}
