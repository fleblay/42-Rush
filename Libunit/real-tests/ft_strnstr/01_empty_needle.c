/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_empty_needle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:02:24 by gusalle           #+#    #+#             */
/*   Updated: 2022/01/09 19:54:33 by gusalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strnstr.h"
#include "libft.h"

int	empty_needle(void)
{
	const char	*haystack = "cerushestcool";
	const char	*needle = "";

	if (ft_strnstr(haystack, needle, 80) == haystack)
		return (0);
	else
		return (-1);
}
