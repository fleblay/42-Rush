/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:09:33 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/20 18:37:05 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <ncurses.h>
# include <stdlib.h>
// # include <stdio.h>
# include <time.h>
# include <unistd.h>

# define WIN_LIMIT 2048

# define ENDL printf("\n");
# define REAL_VALUE (isPow(WIN_VALUE) ? WIN_VALUE : 2048)
# define MSG( str ) printf( str )
# define AFF_LINE printf( "|---|---|---|---|\n" );
# define CLEAR printf("\e[1;1H\e[2J");

# define FREE_ALL data_clear( inner_win_tab, 1)
# define GET_COLOR(x) 1 * ( x == 2048 ) + 2 * ( x == 1024 ) + 3 * ( x == 512 ) + 4 * ( x == 256 ) + 5 * ( x == 128 ) \
						+ 6 * ( x == 64 ) + 7 * ( x == 32 ) + 8 * ( x == 16 ) + 9 * ( x == 8 ) + 10 * ( x == 4 ) + 11 * ( x == 2 ) + 12 * ( !x ) 

enum e_other
{
	DOWN,
	UP,
	LEFT,
	RIGHT
};

enum e_const
{
	WIN_VALUE = 2048
};

// utils:
void 	board_create( int map[4][4], int size );
void	board_print( int map[4][4], int size );
int		board_isFull( int map[4][4], int size );

int		launch(int size, int win_value);

int		generate_number( int map[4][4], int size );
int		isPow( int value );
int		check_goal( int map[4][4], int size, int value );
int		is_GameOver( int map[4][4], int size );

// move:
int		board_down( int map[4][4], int size);
int		board_up( int map[4][4], int size);
int		board_left( int map[4][4], int size);
int		board_right( int map[4][4], int size);

int		down( int map[4][4], int index, int size, int *score );
int		up( int map[4][4], int index, int size, int *score );
int		left( int map[4][4], int index, int size, int *score );
int		right( int map[4][4], int index, int size, int *score );

int		fusion( int map[4][4], int y1, int x1, int y2, int x2);
int		make_move( int map[4][4], int y1, int x1, int y2, int x2);

// libft
int		ft_strlen( char *s );
void 	ft_error( char *s );

// windows
int	destroy_inner_win_partial(WINDOW *inner_win_tab[4][4], int imax, int jmax);
int	create_inner_win(WINDOW *inner_win_tab[4][4]);
int	destroy_inner_win(WINDOW *inner_win_tab[4][4]);
int	resize_inner_win(WINDOW *inner_win_tab[4][4]);
int	refresh_inner_win(WINDOW *inner_win_tab[4][4]);
int print_numbers_in_inner_win(int number_tab[4][4], WINDOW *inner_win_tab[4][4]);
int	treat_key_pres(int key, int number_tab[4][4]);
int	gtfo(WINDOW *inner_win_tab[4][4]);

int draw_screen(WINDOW *inner_win_tab[4][4], int map[4][4]);
int draw_message(char *msg);

int data_clear(WINDOW *inner_win_tab[4][4], int ret);
int	get_max_value_on_board(int tab[4][4], int size);


#endif
