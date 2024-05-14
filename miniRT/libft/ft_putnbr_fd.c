/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:30:16 by soljeong          #+#    #+#             */
/*   Updated: 2023/10/20 15:48:07 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_n(int digit, int n, int fd);
static int	ft_get_digit(int n);

void	ft_putnbr_fd(int n, int fd)
{
	int		digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	digit = ft_get_digit(n);
	ft_print_n(digit, n, fd);
}

static int	ft_get_digit(int n)
{
	int	digit;

	digit = 1;
	while (n >= 10)
	{
		n /= 10;
		digit *= 10;
	}
	return (digit);
}

static void	ft_print_n(int digit, int n, int fd)
{
	char	c;

	if (digit == 0)
		return ;
	c = (n / digit) + '0';
	write(fd, &c, 1);
	ft_print_n(digit / 10, n % digit, fd);
	return ;
}
