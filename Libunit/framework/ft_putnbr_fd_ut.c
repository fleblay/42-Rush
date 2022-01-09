/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_ut.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:50:21 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/09 11:51:24 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <unistd.h>

void	ft_putnbr_fd_ut(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd_ut('-', fd);
		n *= -1;
		ft_putnbr_fd_ut(n, fd);
		return ;
	}
	if (n > 9)
	{
		ft_putnbr_fd_ut(n / 10, fd);
		ft_putnbr_fd_ut(n % 10, fd);
	}
	if (n <= 9)
		ft_putchar_fd_ut(n + 48, fd);
}
