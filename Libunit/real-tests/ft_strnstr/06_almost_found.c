/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_almost_found.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:26:14 by gusalle           #+#    #+#             */
/*   Updated: 2022/01/09 19:28:01 by gusalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strnstr.h"
#include "libft.h"
#include <stddef.h>

int	test_almost_found(void)
{
	const char	*haystack = "Ce rush est cool";
	const char	*needle = "est";

	if (ft_strnstr(haystack, needle, 10) == NULL)
		return (0);
	else
		return (-1);
}
