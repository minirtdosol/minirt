/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:31:30 by soljeong          #+#    #+#             */
/*   Updated: 2023/10/20 15:47:02 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iota_len(int n);
static char	*ft_make_str(int idx, int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		idx;
	int		isminus;

	isminus = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		n *= -1;
		isminus = 1;
	}
	idx = ft_iota_len(n) + isminus;
	str = ft_make_str(idx, n);
	if (!str)
		return (NULL);
	if (isminus)
		str[0] = '-';
	return (str);
}

static char	*ft_make_str(int idx, int n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (idx + 1));
	if (!str)
		return (NULL);
	str[idx] = 0;
	while (n > 0)
	{
		str[--idx] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

static int	ft_iota_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
