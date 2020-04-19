/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:12:56 by bykim             #+#    #+#             */
/*   Updated: 2020/04/19 22:05:17 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putnbr(long long n, int fd)
{
	int remainder;

	if (n == 0)
		return ;
	remainder = n % 10;
	putnbr(n / 10, fd);
	write(fd, remainder, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	temp;

	if (n == 0)
	{
		write(fd, n, 1);
		return ;
	}
	temp = n;
	if (temp < 0)
	{
		temp *= -1;
		write(fd, '-', 1);
	}
	putnbr(temp, fd);
}
