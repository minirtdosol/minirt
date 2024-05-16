/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:52:38 by soljeong          #+#    #+#             */
/*   Updated: 2023/10/20 15:49:00 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_arrlen(char const *s, char c);
static int	ft_makearr(char **arr, int arr_len, char const *s, char c);
static int	ft_arrfree(char **arr, int arr_idx);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		arr_len;

	arr_len = ft_arrlen(s, c);
	arr = (char **)malloc(sizeof(char *) * (arr_len + 1));
	if (!arr)
		return (NULL);
	if (!ft_makearr(arr, arr_len, s, c))
		return (NULL);
	return (arr);
}

static int	ft_arrlen(char const *s, char c)
{
	int	idx;
	int	arr_len;

	idx = 0;
	arr_len = 0;
	while (s[idx])
	{
		while (s[idx] && s[idx] == c)
			idx++;
		if (s[idx] && s[idx] != c)
			arr_len++;
		while (s[idx] && s[idx] != c)
			idx++;
	}
	return (arr_len);
}

static int	ft_makearr(char **arr, int arr_len, char const *s, char c)
{
	int	arr_idx;
	int	last;
	int	start;

	last = 0;
	start = 0;
	arr_idx = 0;
	while (arr_idx < arr_len)
	{
		while (s[last] && s[last] == c)
			last++;
		start = last;
		while (s[last] && s[last] != c)
			last++;
		arr[arr_idx] = ft_substr(s, start, last - start);
		if (!arr[arr_idx])
			return (ft_arrfree(arr, arr_idx));
		arr_idx++;
	}
	arr[arr_idx] = 0;
	return (1);
}

static int	ft_arrfree(char **arr, int arr_idx)
{
	while (--arr_idx >= 0)
		free(arr[arr_idx]);
	free(arr);
	return (0);
}
