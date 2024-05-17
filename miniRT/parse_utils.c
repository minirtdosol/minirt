/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokoh <dokoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:49:31 by soljeong          #+#    #+#             */
/*   Updated: 2024/05/17 15:18:33 by dokoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft/libft.h"
#include "scene.h"
#include "print.h"

int	is_rt_file(char *filename)
{
	int	i;

	i = 0;
	if (filename == NULL)
		print_error("Woring file");
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

t_vec3	parse_vec3(char *str)
{
	char	**splited;
	t_vec3	vec3;

	splited = ft_split(str, ',');
	if (splited_len(splited) != 3)
		print_error("Woring content in .rt");
	vec3.x = ft_atod(splited[0]);
	vec3.y = ft_atod(splited[1]);
	vec3.z = ft_atod(splited[2]);
	splited_free(splited);
	return (vec3);
}

t_color3	parse_rgb(char *str)
{
	t_vec3	vec3;

	vec3 = parse_vec3(str);
	if (vec3.x < 0 || vec3.x > 255 || vec3.y < 0 \
	|| vec3.y > 255 || vec3.z < 0 || vec3.z > 255)
		print_error("Wrong rgb");
	vec3.x = vec3.x / 255;
	vec3.y = vec3.y / 255;
	vec3.z = vec3.z / 255;
	return (color3(vec3.x, vec3.y, vec3.z));
}

t_vec3	parse_vec(char *str)
{
	t_vec3	vec;

	vec = parse_vec3(str);
	if (vec.x < -1 || vec.x > 1 || vec.y < -1 || vec.y > 1
		|| vec.z < -1 || vec.z > 1)
		print_error("Wrong vector");
	return (vec);
}

t_point3	parse_point(char *str)
{
	t_vec3	vec3;

	vec3 = parse_vec3(str);
	return (point3(vec3.x, vec3.y, vec3.z));
}
