/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:12:29 by soljeong          #+#    #+#             */
/*   Updated: 2023/10/20 11:28:50 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	*changed;
	unsigned char	ch;

	p = (unsigned char *)b;
	changed = (unsigned char *)b + len;
	ch = (unsigned char)c;
	while (p != changed)
	{
		*p = ch;
		p++;
	}
	return (b);
}
