/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_basic_test_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:20:52 by gusalle           #+#    #+#             */
/*   Updated: 2022/01/09 19:22:44 by gusalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strnstr.h"
#include "libft.h"
#include <stddef.h>

int	basic_notfound(void)
{
	const char	*haystack = "Ce rush est cool";
	const char	*needle = "rusH";

	if (ft_strnstr(haystack, needle, 80) == NULL)
		return (0);
	else
		return (-1);
}
