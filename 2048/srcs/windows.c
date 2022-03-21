/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:00:00 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/20 18:14:38 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	get_max_value_on_board(int tab[4][4], int size)
{
	int ret;
	int	i;
	int	j;

	ret = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i][j] > ret)
				ret = tab[i][j];
			j++;
		}
		i++;
	}
	return (ret);
}

int	destroy_inner_win_partial(WINDOW *inner_win_tab[4][4], int imax, int jmax)
{
	int	i;
	int	j;

	i = 0;

	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == imax)
			{
				if (j <= jmax)
					delwin(inner_win_tab[i][j]);
				else 
					return (1);
			}
			else
				delwin(inner_win_tab[i][j]);
			j++;
		}
		i++;
	}
	return (1);
}


int	create_inner_win(WINDOW *inner_win_tab[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			inner_win_tab[i][j] = newwin(LINES / 4, COLS / 4, i * LINES / 4, j * COLS / 4);
			if (!inner_win_tab[i][j])
				return (destroy_inner_win_partial(inner_win_tab, i, j), 0);
			// box(inner_win_tab[i][j], 0, 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	destroy_inner_win(WINDOW *inner_win_tab[4][4])
{
	int	i;
	int	j;

	i = 0;

	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			delwin(inner_win_tab[i][j]);
			j++;
		}
		i++;
	}
	return (1);
}

int	resize_inner_win(WINDOW *inner_win_tab[4][4])
{
	int	i;
	int	j;

	i = 0;

	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if(wresize(inner_win_tab[i][j], LINES / 4, COLS / 4) == ERR)
				return (ft_error("while resizing inner window"), 0);
			if(mvwin(inner_win_tab[i][j], i * LINES / 4, j * COLS / 4) == ERR)
				return (ft_error("while moving inner window"), 0);
			if(werase(inner_win_tab[i][j]) == ERR)
				return (ft_error("while clearing inner window"), 0);
			// box(inner_win_tab[i][j], 0, 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	refresh_inner_win(WINDOW *inner_win_tab[4][4])
{
	int	i;
	int	j;

	i = 0;

	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if(wrefresh(inner_win_tab[i][j]) == ERR)
				return (ft_error("while refreshin inner_windows"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	treat_key_pres(int key, int number_tab[4][4])
{
	static int count = 0;
	int ret = 0;

	if (key == 97 || key == 260)
		ret = board_left( number_tab, 4);
	else if (key == 100 || key == 261)
		ret = board_right( number_tab, 4);
	else if (key == 119 || key == 259)
		ret = board_up( number_tab, 4);
	else if (key == 115 || key == 258)
		ret = board_down( number_tab, 4);
	count++;
	return (ret);
}

int	gtfo(WINDOW *inner_win_tab[4][4])
{
	resetty();
	destroy_inner_win(inner_win_tab);
	if (delwin(stdscr) == ERR)
		return (ft_error("while ending window"), 2);
	if (endwin() == ERR)
		return (ft_error("while ending window"), 2);
	return (1);
}
