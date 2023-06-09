/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:59:25 by gusalle           #+#    #+#             */
/*   Updated: 2022/01/09 21:00:12 by gusalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	null_test(void)
{
	if (ft_lstlast(NULL) == NULL)
		return (0);
	else
		return (-1);
}
