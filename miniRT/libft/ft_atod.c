/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:59:13 by soljeong          #+#    #+#             */
/*   Updated: 2024/05/16 17:01:08 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static double	ft_integerpart(char **str, int flag);
static double	ft_make_double(char *str, int flag);
static int		ft_isspace(int c);
static void		ft_numerr(void);

double	ft_atod(char *str)
{
	int	flag;

	flag = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	if (*str == '\0')
	{
		ft_numerr();
	}
	return ((double)flag * ft_make_double(str, flag));
}

static double	ft_make_double(char *str, int flag)
{
	double	total;
	double	decimal;

	total = ft_integerpart(&str, flag);
	decimal = 0.1L;
	if (*str == '\n')
		return (total);
	if (*str && !ft_isdigit(*str) && !(*str++ == '.'))
	{
		ft_numerr();
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_numerr();
		total += (*str++ - '0') * decimal;
		decimal *= 0.1;
	}
	return (total);
}

static double	ft_integerpart(char **str, int flag)
{
	double	integerpart;

	integerpart = 0L;
	while (ft_isdigit(**str))
	{
		if ((!flag && integerpart > 2147483647)
			|| (flag && integerpart > 2147483648))
			ft_numerr();
		integerpart = integerpart * 10 + **str - '0';
		(*str)++;
	}
	return (integerpart);
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

static void	ft_numerr(void)
{
	printf("Wrong number Error\n");
	exit(1);
}
