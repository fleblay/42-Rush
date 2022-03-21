/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:09:23 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/20 18:37:42 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <signal.h>

int g_play = 1;

void	handle_sigint(int signal_number)
{
	if (signal_number == SIGINT)
		g_play = 0;
	erase(); 
	mvprintw(LINES / 2, (COLS / 2) - 12, "Press another key to exit");
	refresh();
}

int data_clear(WINDOW *inner_win_tab[4][4], int ret)
{
	gtfo(inner_win_tab);
	return ret;
}

int launch(int size, int win_value)
{
	WINDOW	*win;
	WINDOW	*inner_win_tab[4][4];

	(void)win_value;

	// Creating the board
	int map[4][4];
	board_create( map, size );

	// INIT WINDS
	int		key;	
	
	key = 0;
	win = initscr();
	if (win == NULL)
		return (ft_error("while init screen"), 1);
	if (has_colors() == TRUE && can_change_color() == TRUE && start_color() == ERR)
		return (ft_error("while init colors"),delwin(stdscr), endwin(), 1);
	if (noecho() == ERR)
		return (ft_error("while setting noecho"), delwin(stdscr), endwin(), 1);
	if (cbreak() == ERR)
		return (ft_error("while setting cbreak"), delwin(stdscr), endwin(), 1);
	if (curs_set(0) == ERR)
		return (ft_error("while setting curs_set"), delwin(stdscr), endwin(), 1);
	if (keypad(win, 1) == ERR)
		return (ft_error("while setting keypad"), delwin(stdscr), endwin(), 1);
	if (!create_inner_win(inner_win_tab))
		return (ft_error("while setting inner windows"), delwin(stdscr), endwin(), 1);
	savetty();

	// PRE AFFICHAGE:
	if (draw_screen( inner_win_tab, map ))
		return FREE_ALL;

	// Game
	while (g_play)
	{
		if (is_GameOver(map, size) || get_max_value_on_board(map, size) >= win_value || get_max_value_on_board(map, size) == WIN_LIMIT)
		{
			//tester avec la plus petite fenetre
			if (!is_GameOver(map, size) && get_max_value_on_board(map, size) < WIN_LIMIT)
				draw_message( "YOU WIN. Press A to continue");
			else if (!is_GameOver(map, size))
			{
				draw_message( "YOU WIN. Press a key to quit");
				key = getch();
				break;
			}
			else
			{
				draw_message( "Game Over LOSER, Press a key to quit" );
				key = getch();
				break;
			}
			key = getch();
			if (key == 97)
			{
				win_value = WIN_LIMIT;
				if (erase() == ERR)
					return (ft_error("while erasing screen"), FREE_ALL);
				if(!resize_inner_win(inner_win_tab))
					return (ft_error("while resizing inner windows"), FREE_ALL);
				if (draw_screen( inner_win_tab, map ))
					return (ft_error("while drawing screen"), FREE_ALL);
				continue ;
			}
			else
				break;
		}
		key = getch();
		if (key == ERR)
			return (ft_error("while getting next key"), FREE_ALL);
		if (erase() == ERR)
			return (ft_error("while erasing screen"), FREE_ALL);
		if (key == 27)
			break;
		if (LINES < 13 || COLS < 41)
		{
			if (COLS > 12 && draw_message( "Too Small"))
				return (ft_error("while printing too small screen"), FREE_ALL);
			continue ;
		}
		treat_key_pres(key, map);
		if(!resize_inner_win(inner_win_tab))
			return (ft_error("while resizing inner windows"), FREE_ALL);
		if (draw_screen( inner_win_tab, map ))
			return (ft_error("while drawing screen"), FREE_ALL);
	}
	return data_clear( inner_win_tab, 0);
}

int main( void )
{
	int size = 4;
	srand( time( NULL ) );
	signal(SIGQUIT, SIG_IGN);	
	signal(SIGINT, handle_sigint);
	return (launch(size, REAL_VALUE));
}

