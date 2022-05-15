/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:23:21 by fle-blay          #+#    #+#             */
/*   Updated: 2022/05/15 15:23:46 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"
#include <stdio.h>
#include <stdlib.h>

int	insert_dict_entry(t_game *game, char *buf)
{
	t_list	*new_entry;
	char	*new_word;

	new_word = ft_strdup(buf);
	if (!new_word)
	{
		ft_putstr_fd("Malloc Error\n", 2);
		ft_lstclear(&game->dict, free);
		return (0);
	}
	to_upper_str(new_word);
	new_entry = ft_lstnew(new_word);
	if (!new_entry)
	{
		ft_putstr_fd("Malloc Error\n", 2);
		free(new_word);
		ft_lstclear(&game->dict, free);
		return (0);
	}
	ft_lstadd_back(&game->dict, new_entry);
	return (1);
}

int	load_dict(t_game *game, char *file_name)
{
	FILE	*file;
	char	buf[7]; 
	size_t	read_ret;

	file = fopen(file_name, "r");
	if (!file)
	{
		ft_putstr_fd("Error while opening dict file\n", 2);
		return (0);
	}
	read_ret = 1;
	while (read_ret > 0)
	{
		ft_bzero(buf, 7);
		read_ret = fread(buf, sizeof(char), 6, file);
		if (read_ret <= 0)
			break ;
		if (!verify_read_result(buf))
		{
			ft_putstr_fd("Non conform dict entry\n", 2);
			return (ft_lstclear(&game->dict, free), fclose(file), 0);
		}
		if (insert_dict_entry(game, buf) == 0)
		{
			ft_putstr_fd("Error while inserting new dict entry\n", 2);
			return (fclose(file), 0);
		}
	}
	if (ferror(file))
	{
		ft_putstr_fd("Error while reading dict file\n", 2);
		return (fclose(file), 0);
	}
	game->dict_size = ft_lstsize(game->dict);
	if (game->dict_size == 0)
		return (fclose(file), ft_putstr_fd("Error : Empty dict\n", 2), 0);
	return (fclose(file), 1);
}
