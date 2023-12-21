/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:00:06 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/12/21 19:53:32 by ybouchra         ###   ########.fr       */
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
	mlx_image_t*	S_texture; // youssef
	mlx_image_t*	W_texture; // youssef
	mlx_image_t*	E_texture; // youssef
} t_mlx;

typedef struct s_info
{
	int		fd;
	char 	**file;
	int 	height;
	int		start;
	char	**NO_txt;
	char	**WE_txt;
	char	**SO_txt;
	char	**EA_txt;
	char	**C_colors;
	char	**F_colors;
	int		C_tab[3];
	int		F_tab[3];
}	t_info;

typedef struct s_player {
	int		x; // position with pixels x
	int		y; // position with pixels y
	int		mv; // 0 RC
	int		rt; // 0 RC
	float	rad_current_view; // M_PI / 2  || 0 || 3M_PY/3 || M_PI view of player p p/2 0 3p/2
	int		view_angle; // 60 RC
	int		score; // 0
	int		mv_speed; // 3
	int		rt_speed; // 2 * (M_P1 / 180)
}t_player;

typedef struct s_map {
	// t_player		*player;
	int				fd;
	int				max_height;
	int				max_width; // max len line
	int				height; // youssef
	int				width; // youssef
	int				block_size; // 60  x = 60*x +60/2 | y = 60*y + 60/2
	int				floor_color[3]; // youssef int tab[3] = {20, 285, 56};
	int				ceiling_color[3]; // youssef int tab[3] = {20, 285, 56};
	char			**map; // youssef
}t_map;

void	check_file(t_info *info, t_map *map);
void	check_map(t_map *vars, t_info *info);
char	*get_spaces(int size);
int		max_width( char **f_map);
int 	height_map(char **f_map);
int		skip_items(char **f_map);
void	valid_items(t_info *info);
void    split_items(t_info *info);
void 	ft_puterr(char *str);
char	*get_next_line(int fd);
int		is_exist(char *str, int c);
int		nbr_item(char *s, char c);  
void	free_items(t_info *info);
void	ft_clearr(char **arr);
void    check_paths(t_info *info, char **str);
void    pars_rgb(t_info *info, char *data_color, int tab[3]);
int 	valid_char(char **map);
void	print_map(char **vars);

void put_mini_map(t_map *map, mlx_image_t* img);
void put_area(int x, int y, int size, int color, mlx_image_t* img);
void	put_player(int x, int y, int size, t_map *map, mlx_image_t* img);

#endif