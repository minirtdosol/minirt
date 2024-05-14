/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:54:00 by soljeong          #+#    #+#             */
/*   Updated: 2023/10/20 11:05:48 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	unsigned char	*p;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	p = (unsigned char *)s + n;
	while (str != p)
	{
		if (*str == ch)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
