/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <fle-blay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:33:18 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/10 15:15:47 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtable.h"

void	ft_memcpy(char *dst, char *src, size_t size)
{
	long int	*ldst;
	long int	*lsrc;

	while (size % sizeof(long int) && size > 0)
	{
		*dst = *src;
		dst++;
		src++;
		--size;
	}
	ldst = (long int *)dst;
	lsrc = (long int *)src;
	while (size > 0)
	{
		*ldst = *lsrc;
		ldst++;
		lsrc++;
		size -= 8;
	}
}

void	ft_memcpy_old(char *dst, char *src, size_t size)
{
	while (size > 0)
	{
		*dst = *src;
		dst++;
		src++;
		--size;
	}
}

char	*ft_realloc(char *s, size_t old, ssize_t *to_add, char **tmp)
{
	char	*ret;

	*tmp = s;
	*to_add = !old * BUFFER_SIZE + old;
	ret = NULL;
	while (!ret && *to_add >= BUFFER_SIZE)
	{
		ret = (char *)malloc((old + *to_add + 1) * sizeof(char));
		if (!ret)
			*to_add >>= 1;
	}
	if (!ret)
		return (NULL);
	if (!s)
		return (ret);
	ft_memcpy(ret, s, old);
	return (ret);
}
