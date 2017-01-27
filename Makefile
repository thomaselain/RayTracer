# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aljourda <aljourda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 11:28:20 by aljourda          #+#    #+#              #
#    Updated: 2017/01/27 17:05:26 by telain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#	Install Debian
#	apt-get install libsdl2-dev
#	apt-get install libsdl2-ttf-dev

NAME = RT

OS := $(shell uname -o)
SRC := $(shell find ./srcs -name *.c)
INC := -I includes/libft -I includes/graphics -I includes/core -I includes/matrix_vector -I includes/parser -I includes/threads -I includes/color
OBJ := $(SRC:.c=.o)

CFLAGS := $(INC) -g -F libs/ -Wall -Wextra #-Werror
LDFLAGS := -L libs/libft/ -L libs/matrix_vector/ -lft -lpthread -lm -lmv

ifeq ($(OS),GNU/Linux)
	CC := gcc
	SDL := -lSDL2 -lSDL2_ttf
	CFLAGS += -D'OS=linux'
	LDFLAGS += $(SDL)
else
	CC=clang
	MLX := -framework OpenGL -framework AppKit -lmlx
	SDL := -F libs/ -framework SDL2 -framework SDL2_ttf
	LDFLAGS += $(SDL) $(MLX)
endif


all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libs/libft
	@make -C libs/matrix_vector
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LIBS) -fsanitize=address

clean:
	make clean -C libs/libft/
	@make clean -C libs/matrix_vector
	@rm -Rf $(OBJ)

fclean: clean
	make fclean -C libs/libft/
	@make fclean -C libs/matrix_vector
	@rm -Rf $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
