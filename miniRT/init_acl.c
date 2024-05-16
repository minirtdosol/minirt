/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_acl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:30:21 by soljeong          #+#    #+#             */
/*   Updated: 2024/05/16 15:10:54 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "parse.h"
#include "libft/libft.h"
#include "scene.h"
#include "print.h"

void	init_acl(char **line_splited, t_scene *scene, int *acl, int acl_num)
{
	if (acl[acl_num])
		print_error("Woring content in .rt");
	acl[acl_num] = 1;
	if (acl_num == AMBIENT)
		init_ambient(line_splited, scene);
	else if (acl_num == CAMERA)
		init_camera(line_splited, scene);
	else if (acl_num == LIGHT)
		init_light(line_splited, scene);
}

void	init_camera(char **line_splited, t_scene *scene)
{
	t_point3	point;
	t_vec3		vec;
	double		fov;

	point = parse_point(line_splited[1]);
	vec = parse_vec(line_splited[2]);
	fov = ft_atod(line_splited[3]);
	if (fov < 0 || fov > 180)
		print_error("Wrong fov");
	scene->camera = camera_init(point, vec, fov);
}

void	init_ambient(char **line_splited, t_scene *scene)
{
	double		ka;
	t_color3	color;

	ka = ft_atod(line_splited[1]);
	if (ka < 0 || ka > 1)
		print_error("Wrong ambient");
	color = parse_rgb(line_splited[2]);
	scene->ambient = vmult(color, ka);
}

void	init_light(char **line_splited, t_scene *scene)
{
	t_vec3	point;
	double	bright_ratio;
	t_vec3	color;

	point = parse_point(line_splited[1]);
	bright_ratio = ft_atod(line_splited[2]);
	if (bright_ratio < 0 || bright_ratio > 1)
		print_error("Wrong bright_ratio");
	color = parse_rgb(line_splited[3]);
	scene->light = object(LIGHT_POINT, \
	light_point(point, color, bright_ratio), color3(1, 1, 1));
}
