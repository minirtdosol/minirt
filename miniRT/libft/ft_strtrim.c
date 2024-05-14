/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:35:03 by soljeong          #+#    #+#             */
/*   Updated: 2023/10/14 13:44:00 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	last;

	start = 0;
	last = ft_strlen(s1) - 1;
	if (!ft_strlen(set) || !ft_strlen(s1))
		return (ft_strdup(s1));
	while (ft_strchr((char *)set, s1[start]))
		start++;
	while (ft_strchr((char *)set, s1[last]))
		last--;
	return (ft_substr(s1, start, last - start + 1));
}
