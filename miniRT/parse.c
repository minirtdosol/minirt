/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:10:53 by soljeong          #+#    #+#             */
/*   Updated: 2024/05/13 20:17:05 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include "get_next_line.h"
# include <stdio.h>
# include "libft/libft.h"
# include "parse.h"
# include "print.h"
# include "utils.h"
# define ATOD_ERR 2147483649L;


int	init_ambient(char **line_splited, t_scene *scene);
int	parse_rt(int fd, t_scene *scene)
{
	char	*str;
	char	**splited;
	(void)scene;

	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break;
		if (str[0] == '#')
			continue;
		splited = ft_split(str, ' ');
		if (ft_strncmp(splited[0],"A",2) == 0)
			init_ambient(splited, scene);
		else if (ft_strncmp(splited[0], "C", 2))
		{
			//Camera
			// splited[1]은 x,y,z (쉼표로 구분)
			// splited[1] 3d normalized orientation vector x,y,z(쉼표로 구분) -1 ~ 1 사이
			// FOV 0 ~ 180
		}
		else if (ft_strncmp(splited[0], "L", 2))
		{
			// Light
			// splited[1] light point;
			// light brightness 0 ~ 1
		}
		else if (ft_strncmp(splited[0], "sp", 3)
		|| ft_strncmp(splited[0], "pl", 3)
		|| ft_strncmp(splited[0], "cy", 3))
		//
		{

		}
		else
		{
			print_error("Wrong content in .rt file");
			exit(1);
		}
	}
	return (0);
}

// 쉼표 splited해서 3개 반환하는 함수
// t_vec3 반환함

t_vec3 *parse_vec3(char *str)
{
	t_vec3	*vec3;
	char	**splited;

	vec3 = malloc(sizeof(t_vec3));
	if (!vec3)
		exit(1);
	splited = ft_split(str, ',');
	vec3->x = ft_atod(splited[0]);
	vec3->y = ft_atod(splited[1]);
	vec3->z = ft_atod(splited[2]);
	return (vec3);
}
t_vec3	*vec3_to_rgb(t_vec3 *vec3)
{

	if (vec3->x < 0 || vec3->x > 256 || vec3->y < 0 \
	|| vec3->y > 256 || vec3->z < 0 || vec3->z > 256)
		print_error("Wrong ambient");
	vec3->x = vec3->x / 255;
	vec3->y = vec3->y / 255;
	vec3->z = vec3->z / 255;
	return (vec3);
}

int	init_ambient(char **line_splited, t_scene *scene)
{
	double	ka;
	t_vec3	*vec3;
	(void)scene;

	ka = ft_atod(line_splited[1]);
	if (ka < 0 || ka > 1)
		print_error("Wrong ambient");
	vec3 = parse_vec3(line_splited[2]);
	vec3 = vec3_to_rgb(vec3);
	// splited_rgb = ft_split(line_splited[2], ',');
	// x = ft_atod(splited_rgb[0]);
	// y = ft_atod(splited_rgb[1]);
	// z = ft_atod(splited_rgb[2]);
	scene->ambient = vmult(color3(vec3->x, vec3->y, vec3->z), ka);
	
	// ambient lighting (주변광)
	// splited[1]은 0.0~1.0
	// splited[2]은 255,255,255 (0~255) (쉼표로 구분) 쉼표 splited (RGB)
	return (SUCCESS);
}

// int	init_light(char **line_splited, t_scene *scene)
// {
// 			// Light 위치 (x,y,z) point3
// 			// splited[1] light point; 
// 			// light brightness 0 ~ 1 bright ratio
// 			// color
		

// }