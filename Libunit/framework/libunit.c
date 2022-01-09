/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:40:13 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/09 22:55:36 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libunit.h"

t_test_ut	*new_test_ut(char *test_name, int (*test_fx)(void))
{
	t_test_ut	*new_test;

	new_test = malloc(sizeof(t_test_ut));
	if (!new_test)
		return (NULL);
	new_test->test_name = test_name;
	new_test->test_fx = test_fx;
	return (new_test);
}

int	load_test_ut(t_routine_ut *routine, char *test_name, int (*test_fx)(void))
{
	t_test_ut	*test;
	t_list_ut	*new_item;

	if (routine->error)
		return (-1);
	test = new_test_ut(test_name, test_fx);
	if (!test)
	{
		routine->error = 1;
		return (-1);
	}
	new_item = ft_lstnew_ut(test);
	if (!new_item)
	{
		free (test);
		routine->error = 1;
		return (-1);
	}
	ft_lstadd_back_ut(&(routine->test_list), new_item);
	return (1);
}

void	fork_ut(t_routine_ut *routine, int *nb_test, char *fx_name, int *sum_ok)
{
	pid_t		child;
	int			child_status;
	t_list_ut	*i;

	i = routine->test_list;
	while (i)
	{
		child = fork();
		if (child == -1)
			break ;
		if (child == 0)
			exit(((t_test_ut *)(i->content))->test_fx());
		if (child > 0)
		{
			print_info_ut(fx_name, ((t_test_ut *)(i->content))->test_name);
			wait(&child_status);
			if (WIFEXITED(child_status))
				print_exited_ut(child_status, routine, sum_ok);
			if (WIFSIGNALED(child_status))
				print_signaled_ut(child_status, routine);
		}
		i = i->next;
		(*nb_test)++;
		routine->test_total++;
	}
}

int	launch_tests_ut(char *tested_fx, t_routine_ut *routine)
{
	int			sum_ok;
	int			nb_test;

	if (!routine || !(routine->test_list) || routine->error == 1)
	{
		ft_putstr_fd_ut("Error Loading test\n", 2);
		return (-2);
	}
	nb_test = 0;
	sum_ok = 0;
	fork_ut(routine, &nb_test, tested_fx, &sum_ok);
	print_summary_ut(sum_ok, nb_test);
	return ((sum_ok != nb_test) * (-1));
}
