# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svassal <svassal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 17:22:12 by svassal           #+#    #+#              #
#    Updated: 2017/01/11 17:35:06 by svassal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libmv.a
COMP =			gcc
SRC_DIR =		srcs
OBJ_DIR =		objs
SRC_FILES =		vector1.c \
				vector2.c \
				vector_access.c \
				vector_add.c \
				vector_div.c \
				vector_init.c \
				vector_mul.c \
				vector_sub.c 
#				matrix1.c \
#				matrix2.c \
#				matrix_access.c \
#				matrix_init.c \
#				matrix_rotation.c
OBJ_FILES =		$(SRC_FILES:.c=.o)
SRC =			$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ =			$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
FLAG =			-Wall -Wextra -Werror -Iincludes
GREEN =			\033[0;32m
CYAN =			\033[0;36m
YELLOW =		\033[0;33m
RED =			\033[0;31m
PURPLE =		\033[0;35m
RESET =			\033[0m

$(NAME) :
		@$(MAKE) -j $(OBJ)
		@ar -rcs $(NAME) $(OBJ) && printf "$(CYAN)Libmv$(RESET) : Built $(YELLOW)library$(RESET)\n"

all :				$(NAME)

clean :
		@rm -rf $(OBJ_DIR) && printf "$(RED)Libmv$(RESET) : Removed $(YELLOW)objs/$(RESET)\n"

fclean :			clean
		@rm -f $(NAME) && printf "$(PURPLE)Libmv$(RESET) : Removed $(YELLOW)library$(RESET)\n"

re :				fclean all

$(OBJ_DIR)/%.o :	$(SRC_DIR)/%.c
		@test -d $(dir $@) || mkdir -p $(dir $@) 2> /dev/null
		@$(COMP) -c $(FLAG) $^ -o $@ && printf "$(GREEN)Libmv$(RESET) : Built $(YELLOW)$@$(RESET)\n"
