/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 09:32:06 by fle-blay          #+#    #+#             */
/*   Updated: 2022/02/13 17:24:08 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "libft.h"

static void	set_strat(t_game *game, int board_size)
{
	int	mod;
	int	i;

	i = 1;
	while (i < board_size)
	{
		mod = game->board[i] % 4;
		if (game->begin[i - 1] == first)
			game->aim[i] = win;
		else
			game->aim[i] = lose;
		if (game->aim[i - 1] == lose && game->board[i] < 4)
			game->aim[i] = win;
		if (game->aim[i] == win && mod != 1)
			game->begin[i] = first;
		if (game->aim[i] == win && mod == 1)
			game->begin[i] = second;
		if (game->aim[i] == lose && mod != 1)
			game->begin[i] = second;
		if (game->aim[i] == lose && mod == 1)
			game->begin[i] = first;
		i++;
	}
}

int	make_strat(t_game *game)
{
	int	board_size;

	board_size = get_board_size(game->board);
	game->aim = (int *)malloc(sizeof(int) * board_size);
	if (!game->aim)
		return (0);
	game->begin = (int *)malloc(sizeof(int) * board_size);
	if (!game->begin)
		return (0);
	game->aim[0] = win;
	if (game->board[0] % 4 != 1)
		game->begin[0] = first;
	else
		game->begin[0] = second;
	set_strat(game, board_size);
	return (1);
}

int	get_ai_choice(t_game game)
{
	int	board_size;
	int	curr_heap_size;
	int	curr_aim;
	int	curr_mod;
	int	choice;

	board_size = get_board_size(game.board);
	if (!board_size)
		return (0);
	curr_heap_size = game.board[board_size - 1];
	curr_mod = game.board[board_size - 1] % 4;
	curr_aim = game.aim[board_size - 1];
	if (curr_aim == win && curr_mod != 1)
		choice = (curr_mod - 1 + 4) % 4;
	if (curr_aim == win && curr_mod == 1)
		choice = 1;
	if (curr_aim == lose && curr_mod != 0)
		choice = (curr_mod) % 4;
	if (curr_aim == lose && curr_mod == 0)
		choice = 1;
	ft_putstr_fd("AI took : ", 1);
	ft_putnbr_fd(choice, 1);
	ft_putendl_fd("", 1);
	return (choice);
}
