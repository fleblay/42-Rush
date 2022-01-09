SRCS		= libunit.c print.c ft_lst_add_back_ut.c ft_lst_clear_ut.c ft_lst_new_ut.c \
			ft_lstdelone_ut.c ft_putstr_fd_ut.c ft_putnbr_fd_ut.c \
			ft_putchar_fd_ut.c
OBJS		= $(SRCS:.c=.o)

HEADER		= libunit.h

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
#CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3

NAME		= libunit.a

#SRCS_BONUS	=
#OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	ar rc $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
