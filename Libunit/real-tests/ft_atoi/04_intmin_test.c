/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_intmin_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:05:37 by gusalle           #+#    #+#             */
/*   Updated: 2022/01/09 18:06:46 by gusalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"
#include "libft.h"

int	test_intmin(void)
{
	if (ft_atoi("-2147483648") == -2147483648)
		return (0);
	else
		return (-1);
}
