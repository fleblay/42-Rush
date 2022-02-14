# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdefonte <cdefonte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/29 12:16:09 by cdefonte          #+#    #+#              #
#    Updated: 2022/02/13 17:09:31 by fle-blay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/
MAP_DIR = ./maps/
LIBFT_DIR = ./libft/

SRC_LST = main.c parsing.c board_utils.c get_input.c ai.c game.c printer.c

INCLUDES = -I$(LIBFT_DIR) -I$(INC_DIR)

SRC = $(addprefix $(SRC_DIR), $(SRC_LST))
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
INC = $(INC_DIR)alcu.h

CC = cc
#CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

all: libft $(NAME)

$(NAME): $(INC) $(OBJ) $(LIBFT_DIR)libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC) $(LIBFT_DIR)libft.a
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

clean:
	$(MAKE) $@ -C $(LIBFT_DIR)
	$(RM) $(OBJ)

fclean:
	$(MAKE) $@ -C $(LIBFT_DIR)
	$(RM) $(OBJ) $(NAME)

re: fclean all

$(LIBFT_DIR)libft.a : libft

libft :
	$(MAKE) bonus -C $(LIBFT_DIR)

.PHONY: all clean fclean re libft

#malloc_test: $(OBJ) ${HEADER} libft
	#$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJ} -L./libft -lft -L. -lmallocator

