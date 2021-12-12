/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ht.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:13:38 by jgiron            #+#    #+#             */
/*   Updated: 2021/12/12 19:13:45 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtable.h"

int	get_sizetab(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '\n')
		{
			i++;
			if (str[1] == '\n')
				break ;
		}
		str++;
	}
	return (i);
}

int	init_ht(char ***ht, ssize_t sizeht)
{
	ssize_t	multiplier;

	multiplier = MAX_MULTIPLIER;
	*ht = NULL;
	while (!*ht && multiplier >= 1)
	{
		*ht = (char **)malloc(multiplier * sizeht * sizeof(char *));
		if (!*ht)
			multiplier /= 2;
	}
	if (!*ht)
		return (-1);
	sizeht *= multiplier;
	while (sizeht--)
		(*ht)[sizeht] = NULL;
	return (multiplier);
}

void	fill_ht(char **ht, char **input, int sizeht, int multiplier)
{
	size_t	j;
	char	*tmp;
	ssize_t	offset;
	ssize_t	size;

	size = multiplier * sizeht;
	while (**input && **input != '\n')
	{
		tmp = *input;
		j = hash2(input, sizeht, multiplier);
		offset = -1;
		while (++offset < size)
		{
			if (j + offset == (size_t)size)
				offset -= size;
			if (!ht[j + offset])
			{
				ht[j + offset] = tmp;
				break ;
			}
		}
		while (**input && **input != '\n')
			(*input)++;
		(*input)++;
	}
}
