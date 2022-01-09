/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_almost_notfound.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:29:21 by gusalle           #+#    #+#             */
/*   Updated: 2022/01/09 19:29:32 by gusalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strnstr.h"
#include "libft.h"
#include <stddef.h>

int	test_almost_notfound(void)
{
	const char	*haystack = "Ce rush est cool";
	const char	*needle = "est";

	if (ft_strnstr(haystack, needle, 10) == NULL)
		return (0);
	else
		return (-1);
}
