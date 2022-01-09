/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_back_ut.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:35:33 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/09 12:05:27 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <stddef.h>

void	ft_lstadd_back_ut(t_list_ut **alst, t_list_ut *new)
{
	t_list_ut	*index;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	index = *alst;
	while (index->next)
		index = index->next;
	index->next = new;
}
