/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:31:44 by fle-blay          #+#    #+#             */
/*   Updated: 2022/02/13 15:07:18 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "libft.h"
#include <errno.h>

void	ft_putstrnn_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (! s)
		return ;
	while (s[i] && s[i] != '\n')
		i++;
	write(fd, s, i);
}

int	check_input(int *board, char *input)
{
	int	board_size;
	int	curr_heap_size;

	board_size = get_board_size(board);
	if (!board_size)
		return (0);
	curr_heap_size = board[board_size - 1];
	if (ft_strcmp("1\n", input) && ft_strcmp("2\n", input)
		&& ft_strcmp("3\n", input))
		return (0);
	if (ft_atoi(input) > curr_heap_size)
		return (0);
	return (ft_atoi(input));
}

int	get_usr_input(int *board, int fd)
{
	char	*tmp;
	int		input_int;
	int		read_fd;

	if (fd == -1)
		read_fd = 0;
	else
		read_fd = fd;
	ft_putstr_fd("Please choose between 1 and 3 items\n", 1);
	tmp = get_next_line(0);
	while (tmp && !check_input(board, tmp))
	{
		ft_putstrnn_fd(tmp, 1);
		ft_putstr_fd(" - Invalid choice\n", 1);
		free(tmp);
		ft_putstr_fd("Please choose between 1 and 3 items\n", 1);
		tmp = get_next_line(0);
	}
	if (!tmp && errno)
		return (ft_putstr_fd("Error during gnl\n", 2), 0);
	if (!tmp)
		return (ft_putstr_fd("Stop that !\n", 2), 0);
	input_int = check_input(board, tmp);
	return (free(tmp), input_int);
}
