/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:49:31 by soljeong          #+#    #+#             */
/*   Updated: 2024/05/13 15:51:37 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft/libft.h"

int	is_rt_file(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
	{
		if (filename[i] == '.')
		{
			if (ft_strncmp(&filename[i], ".rt", 4) == 0)
				return (SUCCESS);
			else
				return (FAIL);
		}
		i++;
	}
	return (FAIL);
}