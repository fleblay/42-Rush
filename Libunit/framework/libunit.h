/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:27:01 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/09 22:43:06 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

typedef struct s_list_ut
{
	void				*content;
	struct s_list_ut	*next;
}						t_list_ut;

typedef struct s_test_ut {
	char	*test_name;
	int		(*test_fx)(void);
}			t_test_ut;

typedef struct s_routine_ut {
	t_list_ut	*test_list;
	int			test_ok;	
	int			test_total;	
	int			success;
	int			error;
}			t_routine_ut;

t_test_ut	*new_test(char *test_name, int (*test_fx)(void));
int			load_test_ut(t_routine_ut *rout, char *tst_name, int (*fx)(void));
int			launch_tests_ut(char *tested_fx, t_routine_ut *routine);
void		print_info_ut(char *tested_fx, char *test_name);
void		print_summary_ut(int ok, int total);
void		print_global_summary_ut(t_routine_ut routine);
void		ft_lstadd_back_ut(t_list_ut **alst, t_list_ut *new);
int			ft_lstsize_ut(t_list_ut *lst);
void		ft_lstclear_ut(t_list_ut **lst, void (*del_ut)(void *));
t_list_ut	*ft_lstnew_ut(void *content);
void		ft_lstdelone_ut(t_list_ut *lst, void (*del_ut)(void *));
void		ft_putstr_fd_ut(char *s, int fd);
void		ft_putnbr_fd_ut(int n, int fd);
void		ft_putchar_fd_ut(char c, int fd);
void		print_signaled_ut(int child_status, t_routine_ut *routine);
void		print_exited_ut(int child_s, t_routine_ut *routine, int *sum_ok);
void		fork_ut(t_routine_ut *rut, int *nb_tst, char *fx_name, int *sum_ok);

#endif
