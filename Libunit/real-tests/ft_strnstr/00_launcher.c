/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:22:14 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/09 19:30:09 by gusalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libunit.h"
#include "ft_strnstr.h"

int	ft_strnstr_launcher(t_routine_ut *routine)
{
	load_test_ut(routine, "empty needle", &empty_needle);
	load_test_ut(routine, "empty haystack", &empty_haystack);
	load_test_ut(routine, "basic test found", &basic_found);
	load_test_ut(routine, "basic test not found", &basic_notfound);
	load_test_ut(routine, "basic test out of bound", &basic_outofbound);
	load_test_ut(routine, "test almost found", &test_almost_found);
	load_test_ut(routine, "test almost not found", &test_almost_notfound);
	launch_tests_ut("FT_STRNSTR", routine);
	ft_lstclear_ut(&(routine->test_list), &free);
	return (0);
}
