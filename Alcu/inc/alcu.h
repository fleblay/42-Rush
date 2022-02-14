/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdefonte <cdefonte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:17:55 by cdefonte          #+#    #+#             */
/*   Updated: 2022/02/13 17:13:32 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

typedef struct s_game
{
	int	*board;
	int	*aim;
	int	*begin;
	int	fd;
	int	turn;
	int	readmap;
	int	choice;
	int	error;
}		t_game;

enum {lose, win};
enum {second, first};

int		line_is_valid(char *line);
int		read_input_from_file(char *filename, int **board, int *fd);
int		read_input_from_stdin(int **board);
int		get_board_size(int *board);
void	print_board(int *board);
int		copy_board(int *old_board, int *new_board);
int		add_line_to_board(int **board, char *new_heap);
void	ft_putstrnn_fd(char *s, int fd);
int		check_input(int *board, char *input);
int		get_usr_input(int *board, int fd);
int		make_strat(t_game *game);
int		get_ai_choice(t_game game);
int		make_move(int **board, int choice, int *turn);
void	destroy_game(t_game *game);
int		is_a_winner(t_game game);
int		open_tty(t_game *game);
int		launch_game(t_game *game);
int		get_max_heap(int *board);
void	print_strat(t_game game);

#endif
