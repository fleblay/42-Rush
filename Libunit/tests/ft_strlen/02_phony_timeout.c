/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_phony_timeout.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:09:02 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/17 14:13:09 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	test_timeout(void)
{
	while (1);
	if (ft_strlen("42") == 2)
		return (0);
	else
		return (-1);
}
