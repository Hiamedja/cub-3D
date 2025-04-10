# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 14:44:10 by hiamedja          #+#    #+#              #
#    Updated: 2023/11/30 00:26:05 by nerrakeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

GET_NEXT_LINE = get_next_line_utils.c get_next_line.c \

PARSING =	ft_check_name get_file \
			init_config parse get_map \
			ft_check_colors ft_check_walls ft_check_walls_utils \
			ft_check_walls_utils2 get_map_utils get_map_utils2 \
			extract_map ft_rgbisnum ft_check_comma\

RAYCASTING =	render ft_events cast ray_direction \
				maths_calcul horizontal_point \
				map_haswall_at vertical_point \
				draw_walls player_moves textures_project\

CUB3D.SRC =	./mandatory/main.c \
			./mandatory/free_array.c \
			./mandatory/initialize.c \
			./mandatory/init_textures.c \
			$(addprefix ./get_next_line/, $(GET_NEXT_LINE)) \
			$(addprefix ./mandatory/parsing/, $(addsuffix .c, $(PARSING))) \
			$(addprefix ./mandatory/raycasting/, $(addsuffix .c, $(RAYCASTING)))

CUB3D_BONUS.SRC =	./bonus/main_bonus.c\
					./bonus/free_array_bonus.c \
					./bonus/initialize_bonus.c \
					./bonus/init_textures_bonus.c \
					$(addprefix ./get_next_line/, $(GET_NEXT_LINE)) \
					$(addprefix ./bonus/parsing/, $(addsuffix _bonus.c, $(PARSING))) \
					$(addprefix ./bonus/raycasting/, $(addsuffix _bonus.c, $(RAYCASTING)))

OBJ = $(CUB3D.SRC:.c=.o)

OBJ_BONUS = $(CUB3D_BONUS.SRC:.c=.o)

INCLUDES = \
		-I ./libft/ \

NAME = cub3D

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(MLXFLAGS) $(INCLUDES) $(OBJ) libft/libft.a -o $(NAME)

all : $(NAME)

bonus : $(OBJ_BONUS)
	make -C libft/
	$(CC) $(CFLAGS) $(MLXFLAGS) $(INCLUDES) $(OBJ_BONUS) libft/libft.a -o $(NAME)

clean :
	make -C libft/ clean
	$(RM) -rf $(OBJ)
	$(RM) -rf $(OBJ_BONUS)

fclean : clean
	make -C libft/ fclean
	$(RM) -rf $(NAME)

re : fclean all
