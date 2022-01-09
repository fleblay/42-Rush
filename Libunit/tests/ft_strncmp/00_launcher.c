/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:22:14 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/09 22:16:45 by gusalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_strncmp.h"
#include "libunit.h"

int	ft_strncmp_launcher(t_routine_ut *routine)
{
	load_test_ut(routine, "Basic test", &basic_test_01);
	launch_tests_ut("FT_STRNCMP", routine);
	ft_lstclear_ut(&(routine->test_list), &free);
	return (0);
}
