/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:21:28 by fle-blay          #+#    #+#             */
/*   Updated: 2022/05/15 15:34:48 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <signal.h>

void	signal_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("\b\bStop doing that\n", 1);
	ft_putstr_fd("Enter you guess : ", 1);
}

int	main(int ac, char *av[])
{
	t_game	game;

	srand(time(NULL));
	ft_memset(&game, 0, sizeof(t_game));
	ft_strlcpy(game.keyboard, "QWERTYUIOPASDFGHJKLZXCVBNM", 27);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	if (ac == 3)
	{
		game.available_pick = av[1];
		game.available_try = av[2];
	}
	else
	{
		game.available_pick = DEFAULT_PICK_DICT;
		game.available_try = DEFAULT_TRY_DICT;
	}
	if (load_dict(&game, game.available_pick) == 0)
		return (ft_putstr_fd("Error while loading dict\n", 2), 1);
	pick_word(&game);
	ft_lstclear(&game.dict, free);
	game.dict = NULL;
	if (load_dict(&game, game.available_try) == 0)
		return (ft_putstr_fd("Error while loading dict\n", 2), 1);
	while (game.try_count < 6)
	{
		display_board(&game);
		get_user_input(&game);
		if (!strcmp(game.try_word[game.try_count++], game.to_find))
		{
			game.win = 1;
			break ;
		}
	}
	display_board(&game);
	if (game.win)
	{
		ft_putstr_fd(GREEN"YOU WON in ", 1);
		ft_putnbr_fd(game.try_count, 1);
		ft_putendl_fd(" round(s)"RESET, 1);
	}
	else
	{
		ft_putstr_fd(RED"YOU LOOSE YOU TWAT (Not so smart hey!)\n"RESET, 1);
		ft_putstr_fd("The word to guess was: ", 1);
		ft_putendl_fd(game.to_find, 1);
	}
	ft_lstclear(&game.dict, free);
	return (0);
}

