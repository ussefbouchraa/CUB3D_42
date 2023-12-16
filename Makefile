# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 10:59:06 by ebelfkih          #+#    #+#              #
#    Updated: 2023/12/10 06:55:11 by ybouchra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
ONAME = cub3d.a 
CC = cc -Wall -Werror -Wextra
MLX_LIBFT = libft/libft.a MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm -L"/Users/$(USER)/.brew/opt/glfw/lib" #mac os
# MLX_LIBFT = libft/libft.a MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm # linux os
LIBFT = cd libft && make all
RM = rm -f
AR = ar rc
FILES = code/draw_mini_map.c code/cub3d.c
OBJ = $(FILES:.c=.o)

%.o : %.c code/cub3d.h libft/libft.h
	$(CC) -o $@ -c $<

$(NAME) : $(OBJ)
	$(LIBFT)
	$(AR) $(ONAME) $^
	$(CC) $(ONAME) $(MLX_LIBFT) -o $@

all :
	$(LIBFT)
	$(CC) $(FILES) -o $(NAME) $(MLX_LIBFT) 

clean :
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(ONAME)



re: fclean all

.PHONY = clean fclean re all