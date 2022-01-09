/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_ut.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:37:43 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/09 11:48:21 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <stdlib.h>

void	ft_lstdelone_ut(t_list_ut *lst, void (*del_ut)(void *))
{
	if (lst == NULL)
		return ;
	if (del_ut)
		(*del_ut)(lst->content);
	free(lst);
}
