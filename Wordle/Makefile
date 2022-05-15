SRCS_DIR	= ./src
SRCS_LIST	= wordle.c word_utils.c dict_utils.c display.c\
			user_input.c
SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_LIST))

HEADER_DIR	= ./inc
HEADER_LIST	= wordle.h
HEADER		= $(addprefix $(HEADER_DIR)/, $(HEADER_LIST))

OBJS_DIR	= ./obj
OBJS_LIST	= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

LIBFT_OBJ	= libft.a

#CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror -g3 

CC			= gcc
NAME		= wordle

all	: $(NAME)

$(OBJS_DIR)	:
	mkdir -p $@

$(OBJS_DIR)/%.o	: $(SRCS_DIR)/%.c $(HEADER) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -I $(HEADER_DIR) -o $@

$(NAME)	: $(OBJS_LIST) $(HEADER) Libft/$(LIBFT_OBJ)
	$(CC) $(CFLAGS) $(OBJS_LIST) Libft/$(LIBFT_OBJ) -o $@

Libft/$(LIBFT_OBJ) :
	make bonus -C Libft

clean	:
	rm -rf $(OBJS_DIR)
	make clean -C Libft
	rm -rf tags

fclean	: clean
	rm -rf $(NAME)
	make fclean -C Libft

re	: fclean all

.PHONY : all clean fclean re
