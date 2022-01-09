/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_basic_test_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:19:55 by gusalle           #+#    #+#             */
/*   Updated: 2022/01/09 19:19:57 by gusalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strnstr.h"
#include "libft.h"

int	basic_found(void)
{
	const char	*haystack = "Ce rush est cool";
	const char	*needle = "rush";

	if (ft_strnstr(haystack, needle, 80) == haystack + 3)
		return (0);
	else
		return (-1);
}
