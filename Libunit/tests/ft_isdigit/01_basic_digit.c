/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:16:12 by gusalle           #+#    #+#             */
/*   Updated: 2022/01/09 21:16:43 by gusalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	basic_digit(void)
{
	if (ft_isdigit('0') == 1)
		return (0);
	else
		return (-1);
}
