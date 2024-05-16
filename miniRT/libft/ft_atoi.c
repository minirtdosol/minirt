/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:43:57 by soljeong          #+#    #+#             */
/*   Updated: 2023/10/20 17:30:13 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);
static int	ft_atoi_return(unsigned long long num, int flag, int start, int i);

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	int					flag;
	int					i;
	int					start;

	i = 0;
	num = 0;
	flag = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{	
		if (str[i++] == '-')
		flag = 1;
	}
	while (str[i] == '0')
		i++;
	start = i;
	while (str[i] && ft_isdigit(str[i]))
	{
		num *= 10;
		num += str[i++] - '0';
	}
	return (ft_atoi_return(num, flag, start, i));
}

static int	ft_isspace(int c)
{
	if (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

static int	ft_atoi_return(unsigned long long num, int flag, int start, int i)
{
	if (i - start > 20 && flag)
		return (0);
	if (i - start > 19 && !flag)
		return (-1);
	if (num > 9223372036854775808ULL && flag)
		return (0);
	if (num > 9223372036854775807 && !flag)
		return (-1);
	if (flag)
		return (num * -1);
	return (num);
}
