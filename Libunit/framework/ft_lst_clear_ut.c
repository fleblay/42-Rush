/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear_ut.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:35:59 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/09 11:55:23 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <stddef.h>

void	ft_lstclear_ut(t_list_ut **lst, void (*del_ut)(void *))
{
	t_list_ut	*index;

	index = NULL;
	if (*lst == NULL)
		return ;
	while ((*lst)->next)
	{
		index = *lst;
		*lst = (*lst)->next;
		ft_lstdelone_ut(index, del_ut);
		index = NULL;
	}
	ft_lstdelone_ut(*lst, del_ut);
	*lst = NULL;
}
