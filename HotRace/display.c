/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:13:59 by jgiron            #+#    #+#             */
/*   Updated: 2021/12/12 19:14:43 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtable.h"

long int	put_error(char *for_whom, long int ret)
{
	char	*tmp;

	tmp = strerror(errno);
	ft_putstr_fd(for_whom, 2);
	ft_putstr_fd(tmp, 2);
	write(2, "\n", 1);
	return (ret);
}

void	ft_putstr_newline(char *str)
{
	ssize_t	size;

	size = 0;
	while (str[size] && str[size] != '\n')
		++size;
	write(1, str, size);
}

void	ft_putvalue_newline(char *str)
{
	ssize_t	size;

	size = 0;
	while (str[size] && str[size] != '\n')
		++size;
	++size;
	str += size;
	size = 0;
	while (str[size] && str[size] != '\n')
		++size;
	write(1, str, size);
	write(1, "\n", 1);
}

void	print_not_found(char *str)
{
	ft_putstr_newline(str);
	write(1, ": Not found.\n", 13);
}
