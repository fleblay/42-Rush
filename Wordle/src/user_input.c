/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:32:07 by fle-blay          #+#    #+#             */
/*   Updated: 2022/05/15 15:34:37 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"
#include <stdio.h>
#include <errno.h>

int		find_first_index(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	set_color(t_game *game, char *word, int *word_color)
{
	int	i;

	i = 0;
	ft_strlcpy(game->to_find_color, game->to_find, 7);
	while (i < 5 && word[i])
	{
		if (word[i] == game->to_find_color[i])
		{
			word_color[i] = 2;
			game->to_find_color[i] = '.';
			game->keyboard_color[find_first_index(game->keyboard, word[i])] = 2;
		}
		i++;
	}
	i = 0;
	while (i < 5 && word[i])
	{
		if (word_color[i] != 2 && ft_strchr(game->to_find_color, word[i]))
		{
			word_color[i] = 1;
			*ft_strchr(game->to_find_color, word[i]) = '.';
			if (game->keyboard_color[find_first_index(game->keyboard, word[i])] != 2)
				game->keyboard_color[find_first_index(game->keyboard, word[i])] = 1;
		}
		else if (game->keyboard_color[find_first_index(game->keyboard, word[i])] == 0)
			game->keyboard_color[find_first_index(game->keyboard, word[i])] = 3;
		i++;
	}
}

int	get_user_input(t_game *game)
{
	int		is_in_dict;
	int		i;
	char	*ret;

	ret = NULL;
	is_in_dict = 0;
	while (!is_in_dict)
	{
		ft_putstr_fd("Enter you guess: ", 1);
		free(ret);
		ret = get_next_line(0);
		if (!ret)
		{
			ft_lstclear(&game->dict, free);
			exit (0);
		}
		to_upper_str(ret);
		is_in_dict = is_among_dict(game, ret);
		if (!is_in_dict)
			ft_putstr_fd("Not a valid word!\n", 1);
	}
	i = 0;
	while (i < game->try_count)
		i++;
	ft_strlcpy(game->try_word[i], ret, 7);
	set_color(game, game->try_word[i], game->try_word_color[i]);
	free(ret);
	return (1);
}
