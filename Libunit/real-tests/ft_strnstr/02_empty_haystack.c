/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_empty_haystack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:14:51 by gusalle           #+#    #+#             */
/*   Updated: 2022/01/09 19:14:56 by gusalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strnstr.h"
#include "libft.h"
#include <stddef.h>

int	empty_haystack(void)
{
	const char	*haystack = "";
	const char	*needle = "cool";

	if (ft_strnstr(haystack, needle, 80) == NULL)
		return (0);
	else
		return (-1);
}
