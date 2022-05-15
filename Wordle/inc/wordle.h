/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:22:25 by fle-blay          #+#    #+#             */
/*   Updated: 2022/05/15 15:19:57 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_H
# define WORDLE_H

#include "libft.h"

/*
# define GREEN "\x1b[38;2;0;255;0m"
# define RED "\x1b[38;2;255;0;0m"
# define YELLOW "\x1b[38;2;204;204;0m"
# define GREY "\x1b[38;2;160;160;160m"
*/

# define GREEN "\x1b[1;38;5;10m"
# define RED "\x1b[1;38;5;9m"
# define YELLOW "\x1b[1;38;5;11m"
# define GREY "\x1b[1;38;5;8m"
# define RESET "\x1b[0m"

# define DEFAULT_PICK_DICT "ressources/words-shortlist.txt"
# define DEFAULT_TRY_DICT "ressources/words.txt"

typedef struct	s_game {
	t_list	*dict;
	int		dict_size;
	char	to_find[7];
	char	to_find_color[7];
	int		try_count;
	char	try_word[6][7];
	int		try_word_color[6][7];
	char	*available_pick;
	char	*available_try;
	char	keyboard[27];
	int		keyboard_color[26];
	int		win;
}	t_game;

int		insert_dict_entry(t_game *game, char *buf);
int		load_dict(t_game *game, char *file_name);
void	display_board(t_game *game);
int		is_among_dict(t_game *game, char *guess);
void	pick_word(t_game *game);
int		verify_read_result(char *buf);
int		get_user_input(t_game *game);
void	to_upper_str(char *str);
#endif
