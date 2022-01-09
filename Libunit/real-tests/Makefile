LIBS		= -L ../framework/ -lunit -L libft -lft
HEADERS_DIR	= -I ../framework/ -I . -I libft

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

TEST_DIR_1	= ./ft_strlen/
TEST_LIST_1	= 00_launcher.c 01_basic_test.c
SRCS_TEST_1	= ${addprefix ${TEST_DIR_1}, ${TEST_LIST_1}} 

TEST_DIR_2	= ./ft_strnstr/
TEST_LIST_2	= 00_launcher.c 01_empty_needle.c 02_empty_haystack.c 03_basic_test_1.c 04_basic_test_2.c\
			  05_basic_test_3.c 06_almost_found.c 07_almost_notfound.c
SRCS_TEST_2	= ${addprefix ${TEST_DIR_2}, ${TEST_LIST_2}} 

TEST_DIR_3	= ./ft_atoi/
TEST_LIST_3	= 00_launcher.c 01_basic_test.c 02_basic_test.c 03_intmax_test.c 04_intmin_test.c 05_test_zero.c\
			  06_test_isspace.c 07_test_tail.c 08_test_empty.c 09_test_multiple_signs.c 10_test_only_sign.c\
			  11_test_mix.c

SRCS_TEST_3	= ${addprefix ${TEST_DIR_3}, ${TEST_LIST_3}} 

SRCS		= main.c\
			  $(SRCS_TEST_1)\
			  $(SRCS_TEST_2)\
			  $(SRCS_TEST_3)

DEPS		= $(SRCS:.c=.d)

OBJS		= $(SRCS:.c=.o)

NAME		= real-tests

#SRCS_BONUS	=
#OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	make -C ../framework
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

#%.o : %.c $(HEADER)
#	$(CC) $(CFLAGS) -c $< -o $@ -I../framework/ -I. -Ilibft

%.o : %.c 
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ $(HEADERS_DIR)

clean :
	make clean -C ../framework
	make clean -C libft
	rm -f $(OBJS) $(DEPS)

fclean : clean
	make fclean -C ../framework
	make fclean -C libft
	rm -f $(NAME)

re : fclean all
	make re -C ../framework
	make re -C libft

test : all
	./${NAME}

-include $(DEPS)

.PHONY : all clean fclean re test 
