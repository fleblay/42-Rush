/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:56:44 by fle-blay          #+#    #+#             */
/*   Updated: 2022/02/13 15:50:33 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "libft.h"

int	get_board_size(int *board)
{
	int	i;

	i = 0;
	if (!board)
		return (-1);
	while (board[i] != -1)
		i++;
	return (i);
}

int	get_max_heap(int *board)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	if (!board)
		return (-1);
	while (board[i] != -1)
	{
		if (board[i] > max)
			max = board[i];
		i++;
	}
	return (max);
}

int	copy_board(int *old_board, int *new_board)
{
	int	i;

	i = 0;
	if (!old_board)
		return (0);
	while (old_board[i] != -1)
	{
		new_board[i] = old_board[i];
		i++;
	}
	return (1);
}

int	update_board(int **board, int res)
{
	int	bsize;
	int	*new_board;

	bsize = get_board_size(*board);
	new_board = (int *)malloc((sizeof(int) * (bsize + 2)));
	if (!new_board)
		return (0);
	new_board[bsize + 1] = -1;
	copy_board(*board, new_board);
	new_board[bsize] = res;
	free(*board);
	*board = new_board;
	return (1);
}

int	add_line_to_board(int **board, char *new_heap)
{
	int	res;
	int	error;

	error = 0;
	res = ft_satoi(new_heap, &error);
	if (error || res < 1 || res > 10000)
		return (0);
	if (!*board)
	{
		*board = (int *)malloc((sizeof(int) * 2));
		if (!*board)
			return (0);
		(*board)[0] = res;
		(*board)[1] = -1;
		return (1);
	}
	else
		return (update_board(board, res));
}
