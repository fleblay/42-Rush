/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:16:49 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/09 22:45:12 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "tests.h"
#include <stddef.h>

int	main(void)
{
	t_routine_ut	routine;

	routine.test_list = NULL;
	routine.test_ok = 0;
	routine.test_total = 0;
	routine.success = 0;
	routine.error = 0;
	ft_strlen_launcher(&routine);
	ft_strncmp_launcher(&routine);
	ft_lstlast_launcher(&routine);
	ft_isdigit_launcher(&routine);
	print_global_summary_ut(routine);
	return (routine.success);
}
