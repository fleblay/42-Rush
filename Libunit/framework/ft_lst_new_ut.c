/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new_ut.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:37:01 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/09 11:48:21 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <stdlib.h>

t_list_ut	*ft_lstnew_ut(void *content)
{
	t_list_ut	*elem;

	elem = NULL;
	elem = (t_list_ut *)malloc(sizeof(t_list_ut));
	if (! elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
