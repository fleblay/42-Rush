/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:14:35 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/09 22:18:03 by gusalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <stdlib.h>

void	print_info_ut(char *tested_fx, char *test_name)
{
	ft_putstr_fd_ut(tested_fx, 1);
	ft_putstr_fd_ut(" : ", 1);
	ft_putstr_fd_ut(test_name, 1);
	ft_putstr_fd_ut(" : ", 1);
}

void	print_summary_ut(int ok, int total)
{
	ft_putstr_fd_ut("\n", 1);
	ft_putnbr_fd_ut(ok, 1);
	ft_putstr_fd_ut("/", 1);
	ft_putnbr_fd_ut(total, 1);
	ft_putstr_fd_ut(" tests checked\n", 1);
	ft_putstr_fd_ut("\n", 1);
}

void	print_global_summary_ut(t_routine_ut routine)
{
	ft_putstr_fd_ut("GLOBAL SUMMARY\n", 1);
	ft_putnbr_fd_ut(routine.test_ok, 1);
	ft_putstr_fd_ut("/", 1);
	ft_putnbr_fd_ut(routine.test_total, 1);
	ft_putstr_fd_ut(" tests checked\n", 1);
}

void	print_signaled_ut(int child_status, t_routine_ut *routine)
{
	if (WTERMSIG(child_status) == 11)
		ft_putstr_fd_ut("\x1b[33m[SIGSEGV]\x1b[0m\n", 1);
	if (WTERMSIG(child_status) == 10)
		ft_putstr_fd_ut("\x1b[33m[SIGBUS]\x1b[0m\n", 1);
	if (WTERMSIG(child_status) == 4)
		ft_putstr_fd_ut("\x1b[33m[SIGILL]\x1b[0m\n", 1);
	if (WTERMSIG(child_status) == 6)
		ft_putstr_fd_ut("\x1b[33m[SIGABRT]\x1b[0m\n", 1);
	if (WTERMSIG(child_status) == 13)
		ft_putstr_fd_ut("\x1b[33m[SIGPIPE]\x1b[0m\n", 1);
	if (WTERMSIG(child_status) == 8)
		ft_putstr_fd_ut("\x1b[33m[SIGFPE]\x1b[0m\n", 1);
	routine->success = -1;
}

void	print_exited_ut(int child_status, t_routine_ut *routine, int *sum_ok)
{
	if (WEXITSTATUS(child_status) == 0)
	{
		ft_putstr_fd_ut("\x1b[32m[OK]\x1b[0m\n", 1);
		*sum_ok += (!WEXITSTATUS(child_status));
		routine->test_ok++;
	}
	else
	{
		ft_putstr_fd_ut("\x1b[31m[KO]\x1b[0m\n", 1);
		routine->success = -1;
	}
}
