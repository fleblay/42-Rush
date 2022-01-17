LIBS		= -L ../framework/ -lunit -L broken_libft -lft
HEADERS_DIR	= -I ../framework/ -I . -I broken_libft

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

TEST_DIR_1	= ./ft_strlen/
TEST_LIST_1	= 00_launcher.c 01_basic_test.c 02_phony_timeout.c
SRCS_TEST_1	= ${addprefix ${TEST_DIR_1}, ${TEST_LIST_1}} 

TEST_DIR_2	= ./ft_strncmp/
TEST_LIST_2	= 00_launcher.c 01_basic_test.c
SRCS_TEST_2	= ${addprefix ${TEST_DIR_2}, ${TEST_LIST_2}} 

TEST_DIR_3	= ./ft_lstlast/
TEST_LIST_3	= 00_launcher.c 01_null_test.c
SRCS_TEST_3	= ${addprefix ${TEST_DIR_3}, ${TEST_LIST_3}} 

TEST_DIR_4	= ./ft_isdigit/
TEST_LIST_4	= 00_launcher.c 01_basic_digit.c
SRCS_TEST_4	= ${addprefix ${TEST_DIR_4}, ${TEST_LIST_4}} 

SRCS		= main.c\
			  $(SRCS_TEST_1)\
			  $(SRCS_TEST_2)\
			  $(SRCS_TEST_3)\
			  $(SRCS_TEST_4)

DEPS		= $(SRCS:.c=.d)

OBJS		= $(SRCS:.c=.o)

NAME		= tests_routine

#SRCS_BONUS	=
#OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C broken_libft
	make -C ../framework
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

#%.o : %.c $(HEADER)
#	$(CC) $(CFLAGS) -c $< -o $@ -I../framework/ -I. -Ibroken_libft

%.o : %.c 
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ $(HEADERS_DIR)

clean :
	make clean -C ../framework
	make clean -C broken_libft
	rm -f $(OBJS) $(DEPS)

fclean : clean
	make fclean -C ../framework
	make fclean -C broken_libft
	rm -f $(NAME)

re : fclean all
	make re -C ../framework
	make re -C broken_libft

test : all
	./${NAME}

-include $(DEPS)

.PHONY : all clean fclean re test
