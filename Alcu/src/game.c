/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:25:43 by fle-blay          #+#    #+#             */
/*   Updated: 2022/02/13 16:40:12 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "libft.h"
#include <fcntl.h>

int	make_move(int **board, int choice, int *turn)
{
	int	board_size;

	if (!board || !*board || (*board)[0] == -1)
		return (0);
	if (choice < 1 || choice > 3)
		return (0);
	board_size = get_board_size(*board);
	if (!board_size)
		return (0);
	(*board)[board_size - 1] -= choice;
	if (!(*board)[board_size - 1])
		(*board)[board_size - 1] = -1;
	(*turn)++;
	return (1);
}

void	destroy_game(t_game *game)
{
	int	fd_toread;

	if (!game)
		return ;
	free(game->board);
	free(game->begin);
	free(game->aim);
	game->board = NULL;
	game->begin = NULL;
	game->aim = NULL;
	if (game->fd != -1)
		fd_toread = game->fd;
	else
		fd_toread = 0;
	if (close(fd_toread) == -1)
	{
		ft_putstr_fd("Error on closing\n", 2);
		game->error = 1;
	}
}

int	is_a_winner(t_game game)
{
	if (game.board[0] == -1)
	{
		if (game.turn % 2)
			ft_putstr_fd("\x1b[1;32mYou win !\n\x1b[0m", 1);
		else
			ft_putstr_fd("\x1b[1;31mIA win !\n\x1b[0m", 1);
		return (1);
	}
	return (0);
}

int	open_tty(t_game *game)
{
	if (close(0) == -1)
		return (destroy_game(game), 0);
	game->fd = open("/dev/tty", O_RDONLY);
	if (game->fd == -1)
		return (destroy_game(game), 0);
	return (1);
}

int	launch_game(t_game *game)
{
	while (game->board[0] != -1)
	{
		print_board(game->board);
		game->choice = get_ai_choice(*game);
		make_move(&(game->board), game->choice, &(game->turn));
		if (is_a_winner(*game))
			return (0);
		print_board(game->board);
		game->choice = get_usr_input(game->board, game->fd);
		while (game->choice < 1 || game->choice > 3)
		{
			if (!open_tty(game))
				return (ft_putstr_fd("System Call Error", 2), 1);
			game->choice = get_usr_input(game->board, game->fd);
		}
		make_move(&(game->board), game->choice, &(game->turn));
		if (is_a_winner(*game))
			return (0);
	}
	return (1);
}
