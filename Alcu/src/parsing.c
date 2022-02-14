/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdefonte <cdefonte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:24:31 by cdefonte          #+#    #+#             */
/*   Updated: 2022/02/13 17:03:15 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "libft.h"
#include <fcntl.h>

int	line_is_valid(char *line)
{
	int	len;
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (!line)
		return (ft_putstr_fd("Empty string\n", 2), 0);
	len = ft_strlen(line);
	if (len < 2)
		return (ft_putstr_fd("Only \\n\n", 2), 0);
	if ((len == 2 && !ft_isdigit(line[0])))
		return (ft_putstr_fd("Not a digit\n", 2), 0);
	while (i < len - 2)
	{
		if (!ft_isdigit(line[i]) && line[i] != '+')
			return (ft_putstr_fd("Not a digit nor a plus sign\n", 2), 0);
		if (line[i] == '+')
			sign++;
		if (sign > 1)
			return (ft_putstr_fd("More than one sign\n", 2), 0);
		i++;
	}
	return (1);
}

int	read_input_from_file(char *filename, int **board, int *fd)
{
	char	*tmp;

	if (!filename || ft_strlen(filename) < 5
		|| ft_strcmp(".map", filename + ft_strlen(filename) - 4))
		return (0);
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		return (0);
	tmp = get_next_line(*fd);
	while (tmp)
	{
		if (!line_is_valid(tmp))
			return (free(tmp), 0);
		if (!add_line_to_board(board, tmp))
			return (free(tmp), 0);
		free(tmp);
		tmp = get_next_line(*fd);
	}
	free(tmp);
	return (1);
}

int	read_input_from_stdin(int **board)
{
	char	*tmp;

	tmp = get_next_line(0);
	while (tmp && ft_strcmp(tmp, "\n"))
	{
		if (!line_is_valid(tmp))
			return (free(tmp), 0);
		if (!add_line_to_board(board, tmp))
			return (free(tmp), 0);
		free(tmp);
		tmp = get_next_line(0);
	}
	if (!tmp)
		return (ft_putstr_fd("Missing \\n at the end\n", 2), 0);
	else
		free(tmp);
	return (1);
}
