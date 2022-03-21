NAME	=	2048

INC_DIR	=	./incs
OBJ_DIR	=   ./objs
SRC_DIR = $(shell find srcs -type d)
vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)
# SRCS	= $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))
SRCS =	main.c	\
		draw.c	\
		moves.c	\
		utils.c	\
		windows.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

CC		=	cc

FLAGS	=	-Wall -Werror -Wextra

.PHONY : all
all:	$(NAME)

$(NAME):	$(OBJS) $(INC_DIR)/*.h
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I $(INC_DIR) -lncurses

$(OBJ_DIR)/%.o : %.c $(INC_DIR)/*.h | $(OBJ_DIR)
			$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR) :
	mkdir -p $@

.PHONY : clean
clean:
			rm -rf $(OBJ_DIR)

.PHONY : fclean
fclean:		clean
			rm -f $(NAME)

.PHONY : re
re:			fclean all
