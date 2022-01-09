/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:22:14 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/09 21:06:33 by gusalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lstlast.h"
#include "libunit.h"

int	ft_lstlast_launcher(t_routine_ut *routine)
{
	load_test_ut(routine, "NULL test", &null_test);
	launch_tests_ut("FT_LSTLAST", routine);
	ft_lstclear_ut(&(routine->test_list), &free);
	return (0);
}
