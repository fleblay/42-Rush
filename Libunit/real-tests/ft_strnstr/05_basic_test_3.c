/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_basic_test_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:23:00 by gusalle           #+#    #+#             */
/*   Updated: 2022/01/09 19:24:26 by gusalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strnstr.h"
#include "libft.h"
#include <stddef.h>

int	basic_outofbound(void)
{
	const char	*haystack = "Ce rush est cool";
	const char	*needle = "cool";

	if (ft_strnstr(haystack, needle, 4) == NULL)
		return (0);
	else
		return (-1);
}
