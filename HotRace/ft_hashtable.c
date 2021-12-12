/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:27:19 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/11 17:27:19 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtable.h"

char	*get_input(char	*mainstr)
{
	ssize_t	ret;
	ssize_t	size;
	ssize_t	to_add;
	char	*tmp;

	size = 0;
	ret = BUFFER_SIZE;
	to_add = 0;
	while (ret)
	{
		if (to_add == 0)
			mainstr = ft_realloc(mainstr, size, &to_add, &tmp);
		if (!mainstr)
			return ((char *)put_error("Error: ", (long int) NULL));
		ret = read(0, mainstr + size, to_add);
		if (ret == -1)
			return ((char *)put_error("Error: ", (long int) NULL));
		mainstr[size + ret] = 0;
		size += ret;
		to_add -= ret;
		free(tmp);
		tmp = NULL;
	}
	return (mainstr);
}

size_t	hash2(char **key, int sizeht, int multiplier)
{
	size_t	result;

	result = 0;
	while (**key && **key != '\n')
	{
		result = result * 256 + **key;
		(*key)++;
	}
	(*key)++;
	return (result % (sizeht * multiplier));
}

int	ft_strcmp_newline(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 && *s1 != '\n')
	{
		s1++;
		s2++;
	}
	return (*s1 != *s2);
}

void	get_value(char **ht, char *input, int sizeht, int multiplier)
{
	size_t	j;
	char	*tmp;
	ssize_t	offset;
	size_t	size;

	size = multiplier * sizeht;
	while (*input && *input != '\n')
	{
		tmp = input;
		j = hash2(&input, sizeht, multiplier);
		offset = 0;
		while (ht[j + offset])
		{
			if (j + offset == size)
				offset -= (ssize_t)size;
			if (!ft_strcmp_newline(ht[j + offset], tmp))
			{
				ft_putvalue_newline(ht[j + offset]);
				break ;
			}
			offset++;
		}
		if (!ht[j + offset])
			print_not_found(tmp);
	}
}

int	main(void)
{
	char	*input;
	char	**ht;
	char	*tmp;
	int		multiplier;
	int		size;

	input = get_input(NULL);
	if (!input)
		return (1);
	tmp = input;
	size = get_sizetab(input);
	if (size % 2 == 1 || !size)
		size += 1 + !size;
	multiplier = init_ht(&ht, size / 2);
	if (multiplier == -1 || !multiplier)
		return ((int)put_error("Error: ", 1));
	fill_ht(ht, &input, size / 2, multiplier);
	if (input[0])
		get_value(ht, ++input, size / 2, multiplier);
	free(tmp);
	free(ht);
	return (0);
}
