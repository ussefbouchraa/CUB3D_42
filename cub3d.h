/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:00:06 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/12/28 06:56:07 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <time.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
# endif

typedef struct s_mlx
{
	mlx_t*			mlx ;
	mlx_image_t*	N_texture; // youssef
	mlx_image_t*	W_texture; // youssef
	mlx_image_t*	S_texture; // youssef
	mlx_image_t*	E_texture; // youssef
} t_mlx;

typedef struct s_info
{
	int		fd;
	char 	**file;
	int 	height;
	int 	start;
	int 	items;
	char	**NO_txt;
	char	**WE_txt;
	char	**SO_txt;
	char	**EA_txt;
	char	**C_colors;
	char	**F_colors;
}	t_info;

typedef struct s_player {
	int		x;
	int		y; 
	double	rad_current_view;
	int		view_angle; 
	int		score; 
	int		mv_speed; 
	int		rt_speed; 
}t_player;

typedef struct s_map {
	t_player		*player;
	int				height; // V
	int				max_width;// V
	int				block_size; // 60  x = 60*x +60/2 | y = 60*y + 60/2
	int				floor_color[3]; // V
	int				ceiling_color[3]; // V
	char			**map; // V
}t_map;

void	check_file(t_info *info, t_map *map);
void	check_texture(t_info *info);
void    check_colors(t_info *info, t_map *map);
void	check_map(t_map *vars, t_info *info);
char	*get_spaces(int size);
int		max_width(char **f_map, int start);
int		is_digit(char *arr);
void	start_map(t_info *info, char **f_map);
int 	height_map(t_info *info, char **f_map);
int 	valid_char(char **map);
int		is_exist(char *str, int c);
int		nbr_item(char *s, char c);  
void	ft_clearr(char **arr);
void	free_txt(t_info *info);
void	free_clr(t_info *info);
void	free_all(t_info *info, char **map, char *msg);
void 	ft_puterr(char *str);
int		get_y(char **map);
int		get_x(char **map, int i);
int		just_spaces(char *map_line);
int		increment(char *line, char c);
void	print_map(char **vars);

// void put_mini_map(t_map *map, mlx_image_t* img);
// void put_area(int x, int y, int size, int color, mlx_image_t* img);
// void	put_player(int x, int y, int size, t_map *map, mlx_image_t* img);

#endif