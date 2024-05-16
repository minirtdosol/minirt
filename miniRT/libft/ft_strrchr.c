/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:12:02 by soljeong          #+#    #+#             */
/*   Updated: 2023/10/13 18:56:19 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char			*save;
	unsigned char	ch;

	save = 0;
	ch = (unsigned char) c;
	while (*s)
	{
		if (*s == ch)
			save = (char *)s;
		s++;
	}
	if (ch == 0)
		return ((char *)s);
	return (save);
}
