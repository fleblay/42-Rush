SRCS = 	 display.c ft_hashtable.c ft_putstr_fd.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_substr.c init_ht.c
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror 
.c.o:
	cc $(CFLAGS) -c $< -o $(<:.c=.o)

NAME =  hotrace

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re all
