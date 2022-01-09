/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:22:14 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/09 22:57:35 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_atoi.h"
#include "libunit.h"

int	ft_atoi_launcher(t_routine_ut *routine)
{
	load_test_ut(routine, "Basic test 42", &basic_test_42);
	load_test_ut(routine, "Basic test -42", &basic_test_neg42);
	load_test_ut(routine, "Test INT_MAX", &test_intmax);
	load_test_ut(routine, "Test INT_MIN", &test_intmin);
	load_test_ut(routine, "Test zero", &test_zero);
	load_test_ut(routine, "Test isspace", &test_isspace);
	load_test_ut(routine, "Test tail", &test_tail);
	load_test_ut(routine, "Test empty", &test_empty);
	load_test_ut(routine, "Test multi signs", &test_multi_s);
	load_test_ut(routine, "Test only sign", &test_only_s);
	load_test_ut(routine, "Test mix", &test_mix);
	launch_tests_ut("FT_ATOI", routine);
	ft_lstclear_ut(&(routine->test_list), &free);
	return (0);
}
