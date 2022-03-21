/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:14:28 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/20 18:08:16 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int draw_screen(WINDOW *inner_win_tab[4][4], int map[4][4])
{
	if (!print_numbers_in_inner_win(map, inner_win_tab))
		return (ft_error("while printing array") , 1);
	if (refresh() == ERR)
		return (ft_error("while refreshing") , 1);
	if(!refresh_inner_win(inner_win_tab))
		return (ft_error("while refreshing") , 1);
	return 0;
}

int draw_message(char *msg)
{
	if (!msg)
		return (1);
	if (erase() == ERR)
		return (ft_error("while clearing screen"), 1);
	if (mvprintw(LINES / 2, (COLS / 2) - ft_strlen(msg) / 2, msg) == ERR)
		return (ft_error("while printing \" the message \""), 1);
	if (refresh() == ERR)
		return (ft_error("while refreshing"), 1);
	return 0;
}

int draw_color( WINDOW *inner_win_tab, int number_tab, int xmax, int ymax)
{
	int color = GET_COLOR(number_tab);
	if(wattron(inner_win_tab, COLOR_PAIR(color)) == ERR)
		return(ft_error("while printing"), 0);
	wbkgd(inner_win_tab, COLOR_PAIR(color));	
	if(mvwprintw(inner_win_tab, ymax / 2, xmax / 2 - 1, "%d", number_tab) == ERR)
		return(ft_error("while printing"), 0);
	if(wattroff(inner_win_tab, COLOR_PAIR(color)) == ERR)
		return(ft_error("while printing"), 0);
	return 1;
}

int print_numbers_in_inner_win(int number_tab[4][4], WINDOW *inner_win_tab[4][4])
{
	int	xmax, ymax;
	getmaxyx(inner_win_tab[0][0], ymax, xmax);

	if(init_pair(1, COLOR_BLACK, COLOR_MAGENTA) == ERR)
		return(ft_error("while printing"), 0);
	if(init_pair(2, COLOR_BLACK, COLOR_RED) == ERR)
		return(ft_error("while printing"), 0);
	if(init_pair(3, COLOR_BLACK, COLOR_YELLOW) == ERR)
		return(ft_error("while printing"), 0);
	if(init_pair(4, COLOR_BLACK, COLOR_CYAN) == ERR)
		return(ft_error("while printing"), 0);
	if(init_pair(5, COLOR_BLACK, COLOR_GREEN) == ERR)
		return(ft_error("while printing"), 0);
	if(init_pair(6, COLOR_BLACK, COLOR_BLUE) == ERR)
		return(ft_error("while printing"), 0);
	if(init_pair(7, COLOR_BLACK, COLOR_MAGENTA) == ERR)
		return(ft_error("while printing"), 0);
	if(init_pair(8, COLOR_BLACK, COLOR_RED) == ERR)
		return(ft_error("while printing"), 0);
	if(init_pair(9, COLOR_BLACK, COLOR_YELLOW) == ERR)
		return(ft_error("while printing"), 0);
	if(init_pair(10, COLOR_BLACK, COLOR_CYAN) == ERR)
		return(ft_error("while printing"), 0);
	if(init_pair(11, COLOR_BLACK, COLOR_GREEN) == ERR)
		return(ft_error("while printing"), 0);
	if(init_pair(12, COLOR_BLACK, COLOR_BLACK) == ERR)
		return(ft_error("while printing"), 0);

	for ( int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (!draw_color( inner_win_tab[i][j], number_tab[i][j], xmax, ymax ))
				return 0;

	return (1);
}
