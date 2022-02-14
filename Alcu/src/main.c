/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdefonte <cdefonte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:24:59 by cdefonte          #+#    #+#             */
/*   Updated: 2022/02/13 17:24:38 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game = (t_game){.fd = -1};
	if (argc > 2)
		return (1);
	if (argc == 2)
		game.readmap = read_input_from_file(argv[1], &(game.board), &(game.fd));
	else
	{
		game.readmap = read_input_from_stdin(&(game.board));
		if (!open_tty(&game))
			return (ft_putstr_fd("System Call Error", 2), 1);
	}
	if (!game.readmap || !game.board)
		return (destroy_game(&game), ft_putstr_fd("ERROR\n", 2), 1);
	if (!make_strat(&game))
		return (ft_putstr_fd("Malloc Error\n", 2), destroy_game(&game), 1);
	if (launch_game(&game))
		return (destroy_game(&game), 1);
	destroy_game(&game);
	return (game.error);
}
