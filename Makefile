# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aljourda <aljourda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 11:28:20 by aljourda          #+#    #+#              #
#    Updated: 2017/04/24 14:43:10 by telain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#	Install Debian
#	apt-get install libsdl2-dev
#	apt-get install libsdl2-ttf-dev

NAME = RT

GREEN = \e[32m
RED = \e[31m
WHITE = \e[0m
YELLOW = \e[33m
OS := $(shell uname -o)
SRC_FOLDER := srcs/
SRC := core_main.c \
			color/color.c \
			color/filter1.c \
			color/filter2.c \
			core/circle.c \
			core/color_modifications_recursive.c \
			core/cone.c \
			core/core.c \
			core/cylinder.c \
			core/get_intersection.c \
			core/grid.c \
			core/noise.c \
			core/normal.c \
			core/perlin.c \
			core/plane.c \
			core/rectangle.c \
			core/refraction.c \
			core/shadow.c \
			core/sphere.c \
			core/texture.c \
			core/triangle.c \
			graphics/events.c \
			graphics/img.c \
			graphics/img_modifiers.c \
			graphics/win.c \
			graphics/win_modifiers.c \
			parser/fill_datas_1.c \
			parser/fill_datas_2.c \
			parser/fill_datas_3.c \
			parser/memory.c \
			parser/parse.c \
			parser/parse_camera.c \
			parser/parse_details_1.c \
			parser/parse_details_2.c \
			parser/parse_error.c \
			parser/parse_general_functions_1.c \
			parser/parse_general_functions_2.c \
			parser/parse_general_functions_3.c \
			parser/parse_general_functions_4.c \
			parser/parse_list.c \
			parser/parse_objects.c \
			parser/parse_scene.c \
			parser/parse_structure.c \
			parser/parse_texture.c \
			parser/parse_vectors.c \
			threads/thread.c
SRC := $(addprefix $(SRC_FOLDER),$(SRC))
INC := -I includes/libft -I includes/graphics -I includes/core -I includes/matrix_vector -I includes/parser -I includes/threads -I includes/color
OBJ := $(SRC:.c=.o)

CFLAGS := $(INC) -g -F libs/ -Wall -Wextra -Werror
LDFLAGS := -L libs/libft/ -L libs/matrix_vector/ -lft -lpthread -lm -lmv

ifeq ($(OS),GNU/Linux)
	CC := gcc
	SDL := -lSDL2 -lSDL2_ttf
	CFLAGS += -D'OS=linux'
	LDFLAGS += $(SDL)
else
	CC := gcc
	SDL := -lSDL2 -lSDL2_ttf
	SDL := -F libs/ -framework SDL2 -framework SDL2_ttf
	LDFLAGS += $(SDL) $(MLX)
endif


all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libs/libft
	@make -C libs/matrix_vector
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LIBS) -fsanitize=address

clean:
	@make clean -C libs/libft/
	@make clean -C libs/matrix_vector
	@rm -Rf $(OBJ)
	@rm -Rf capture.bmp

fclean: clean
	@make fclean -C libs/libft/
	@make fclean -C libs/matrix_vector
	@rm -Rf $(NAME)

re: fclean all

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@
	@printf "$(GREEN)  RT$(WHITE)  : Built $(YELLOW) $@\n"
