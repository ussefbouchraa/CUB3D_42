/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:41:23 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/27 23:56:13 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void    height_file(char *av, t_info *info)
{
    char *line;

    line = NULL;
    info->fd = open(av, O_RDONLY, 0777);
    if(info->fd == -1)
        ft_puterr("Error: File Not Found");
    line = get_next_line(info->fd);
    while(line)
    {
        info->height++;
        free(line);
        line = get_next_line(info->fd);
    }
    close(info->fd);
}

void    read_file(char *av, t_info *info)
{
    int i;

    i = 0;
    height_file(av, info);
    if(!info->height)
        ft_puterr("Error: Empty File");
    info->fd = open(av, O_RDONLY);
    info->file = malloc(sizeof(char *) * (info->height + 1));
    if(!info->file)
        ft_puterr("Error: allocation failed !!");  
    while(info->height > i)
        info->file[i++] = get_next_line(info->fd);
    info->file[i] = NULL;

    close(info->fd);
}

void check_extention(char *av)
{
    if (!av || !is_exist(av, '.'))
        ft_puterr("Error: Invalid Argument !!");
    if (ft_strncmp(ft_strrchr(av, '.'), ".cub", ft_strlen(av)))
        ft_puterr("ERROR : Wrong Extention !!");
}



void    init_info(t_info *info, t_map *vars, t_player *player, t_mlx *mlx)
{
    player->y = get_y(vars->map);
    player->x = get_x(vars->map, player->y);
    printf("%s %s\n", info->NO_txt[0], info->NO_txt[1]);
    printf("%s %s\n", info->WE_txt[0], info->WE_txt[1]);
    printf("%s %s\n", info->SO_txt[0], info->SO_txt[1]);
    printf("%s %s\n", info->EA_txt[0], info->EA_txt[1]);
    
    printf("%s %d %d %d\n", info->F_colors[0], vars->floor_color[0], vars->floor_color[1], vars->floor_color[2]);
    printf("%s %d %d %d\n", info->C_colors[0], vars->ceiling_color[0], vars->ceiling_color[1], vars->ceiling_color[2]);

    print_map(vars->map);

    printf("height %d\n", vars->height);
    printf("start %d\n", info->start);
    printf("width%d\n", vars->max_width);
    printf("block_size %d\n", vars->block_size);

    printf("position x %d\n", player->x);
    printf("position y %d\n", player->y);
    printf("score %d\n", player->score);

    // init_texture(mlx, info, vars);
}

int main(int ac, char **av)
{
    t_map map;
    t_player player;
    t_info info;
    t_mlx mlx;

    if(ac == 2)
     {  
        ft_bzero(&info, sizeof(info));
        ft_bzero(&map, sizeof(map));
        ft_bzero(&player, sizeof(player));
        check_extention(av[1]);
        read_file(av[1], &info);
        check_file(&info, &map);
        check_map(&map, &info);
        init_info(&info, &map, &player, &mlx);
        free_clr(&info);
        ft_clearr(map.map);
     }
     else
        write(2, "Error: incorrect syntax !!", 24);
    // while(1);
}
