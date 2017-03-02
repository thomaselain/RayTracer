# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svassal <svassal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 17:22:12 by svassal           #+#    #+#              #
#    Updated: 2016/11/28 10:54:15 by svassal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a
COMP =			gcc
SRC_DIR =		srcs
OBJ_DIR =		objs
SRC_FILES =		ft_abs.c \
				ft_atoi.c \
				ft_atoibase.c \
				ft_bzero.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_ishexa.c \
				ft_islower.c \
				ft_isprint.c \
				ft_isupper.c \
				ft_iswhitespace.c \
				ft_itoa.c \
				ft_itoabase.c \
				ft_lstadd.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstpushback.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c \
				ft_pow.c \
				ft_putchar.c \
				ft_putchar_color.c \
				ft_putchar_color_fd.c \
				ft_putchar_fd.c \
				ft_putendl.c \
				ft_putendl_color.c \
				ft_putendl_color_fd.c \
				ft_putendl_fd.c \
				ft_putnbr.c \
				ft_putnbr_color.c \
				ft_putnbr_color_fd.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_putstr_color.c \
				ft_putstr_color_fd.c \
				ft_putstr_fd.c \
				ft_sqrt.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_strequ.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnequ.c \
				ft_strnew.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strrev.c \
				ft_strsplit.c \
				ft_strstr.c \
				ft_strsub.c \
				ft_strtrim.c \
				ft_swap.c \
				ft_tolower.c \
				ft_toupper.c \
				get_next_line.c
OBJ_FILES = 	$(SRC_FILES:.c=.o)
SRC = 			$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = 			$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
FLAG = 			-Wall -Wextra -Werror -Iincludes
GREEN =			\033[0;32m
CYAN =			\033[0;36m
YELLOW =		\033[0;33m
RED =			\033[0;31m
PURPLE =		\033[0;35m
RESET =			\033[0m

$(NAME) :
	@$(MAKE) -j $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

all :				$(NAME)

clean :
	@rm -rf $(OBJ_DIR)
	printf "$(RED)Libft$(RESET) : Removed $(YELLOW)objs/$(RESET)\n"

fclean :			clean
	@rm -f $(NAME)
	printf "$(PURPLE)Libft$(RESET) : Removed $(YELLOW)library$(RESET)\n"

re :				fclean all

$(OBJ_DIR)/%.o :	$(SRC_DIR)/%.c
	@test -d $(dir $@) || mkdir -p $(dir $@) 2>/dev/null
	@$(COMP) -c $(FLAG) $^ -o $@
