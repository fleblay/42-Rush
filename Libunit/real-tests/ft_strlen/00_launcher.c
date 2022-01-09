/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:22:14 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/09 22:47:16 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_strlen.h"
#include "libunit.h"

int	ft_strlen_launcher(t_routine_ut *routine)
{
	load_test_ut(routine, "Basic test", &basic_test);
	launch_tests_ut("FT_STRLEN", routine);
	ft_lstclear_ut(&(routine->test_list), &free);
	return (0);
}
