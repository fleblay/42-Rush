/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:48:36 by fle-blay          #+#    #+#             */
/*   Updated: 2022/02/13 17:24:26 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alcu.h"

void	print_board(int *board)
{
	int	i;
	int	j;
	int	nb_space;
	int	max_heap;

	i = 0;
	max_heap = get_max_heap(board);
	if (!board)
		return ;
	while (board[i] != -1)
	{
		j = board[i];
		nb_space = max_heap - j;
		while (--nb_space >= 0)
			ft_putstr_fd(" ", 1);
		while (j)
		{
			ft_putstr_fd("| ", 1);
			j--;
		}
		ft_putstr_fd("\n", 1);
		i++;
	}
}
/*
#include <stdio.h>
void	print_strat(t_game game)
{
	int	i;

	i = 0;
	while (game.board[i] != -1)
	{
		printf("heap [%d] : aim [%d], begin[%d]\n", game.board[i], game.aim[i],
		game.begin[i]);
		i++;
	}
}
*/
