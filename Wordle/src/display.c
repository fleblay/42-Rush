/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:24:36 by fle-blay          #+#    #+#             */
/*   Updated: 2022/05/15 15:25:56 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"
#include <stdio.h>
#include <stdlib.h>

void	display_board(t_game *game)
{
	int		i;
	int		full_lines;

	full_lines = 0;

	//clear screen
	ft_putstr_fd("\x1b[2J", 1);
	//move to row 1 column 1
	ft_putstr_fd("\x1b[1;1H", 1);
	while (full_lines < game->try_count)
	{
		i = 0;
		while (i < 5)
		{
			if (game->try_word_color[full_lines][i] == 2)
				ft_putstr_fd(GREEN, 1);
			else if (game->try_word_color[full_lines][i] == 1)
				ft_putstr_fd(YELLOW, 1);
			else
				ft_putstr_fd(GREY, 1);
			ft_putchar_fd(game->try_word[full_lines][i], 1);
				ft_putstr_fd(RESET, 1);
			ft_putchar_fd(' ', 1);
			i++;
		}
		ft_putchar_fd('\n', 1);
		full_lines++;
	}
	while (full_lines < 6)
	{
		ft_putstr_fd("_ _ _ _ _ \n", 1);
		full_lines++;
	}
	ft_putchar_fd('\n', 1);
	i = 0;
	while (game->keyboard[i])
	{
		if (i == 10 || i == 19)
			ft_putstr_fd("\n", 1);
		if (game->keyboard_color[i] == 2)
			ft_putstr_fd(GREEN, 1);
		else if (game->keyboard_color[i] == 1)
			ft_putstr_fd(YELLOW, 1);
		else if (game->keyboard_color[i] == 3)
			ft_putstr_fd(RED, 1);
		ft_putchar_fd(game->keyboard[i], 1);
			ft_putstr_fd(RESET, 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}
