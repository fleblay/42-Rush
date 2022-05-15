/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:25:17 by fle-blay          #+#    #+#             */
/*   Updated: 2022/05/15 15:22:46 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"
#include <stdio.h>
#include <stdlib.h>

void	to_upper_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

int		is_among_dict(t_game *game, char *guess)
{
	t_list	*index;

	index = game->dict;
	while (index && ft_strcmp(guess, (char *)index->content))
	{
		index = index->next;
	}
	if (!index)
		return (0);
	return (1);
}

void	pick_word(t_game *game)
{
	int		index;
	t_list	*pick;

	index = rand() % game->dict_size;
	pick = game->dict;
	while (index)
	{
		pick = pick->next;
		index--;
	}
	ft_strlcpy(game->to_find, pick->content, 7);
}

int	verify_read_result(char *str)
{
	int		i;
	int		len_str;
	
	if (!str)
		return (0);
	len_str = ft_strlen(str);
	if (len_str != 6 && len_str != 5)
		return (ft_putstr_fd("Wrong entry size\n", 2), 0);
	if (len_str == 6)
	{
		if (str[5] != '\n')
			return (ft_putstr_fd("Entry is not newline-terminated\n", 2), 0);
		i = 0;
		while (i < 5)
		{
			if (!ft_isalpha(str[i]))
				return (ft_putstr_fd("Entry is gibberish\n", 2), 0);
			i++;
		}
	}
	else if (len_str == 5)
	{
		i = 0;
		while (i < 5)
		{
			if (!ft_isalpha(str[i]))
				return (ft_putstr_fd("Entry is gibberish\n", 2), 0);
			i++;
		}
		str[5] = '\n';
	}
	return (1);
}
