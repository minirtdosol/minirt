/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:28:28 by soljeong          #+#    #+#             */
/*   Updated: 2024/05/16 15:11:44 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "parse.h"
#include "libft/libft.h"
#include "scene.h"
#include "rotate.h"

void	init_cylinder(char **line_splited, t_object **world)
{
	t_vec3	point;
	t_vec3	vec;
	t_vec3	color;
	double	diameter;
	double	height;

	point = parse_point(line_splited[1]);
	vec = parse_vec(line_splited[2]);
	diameter = ft_atod(line_splited[3]);
	height = ft_atod(line_splited[4]);
	color = parse_rgb(line_splited[5]);
	oadd(world, object(CY, cylinder(point, vec, diameter, height), color));
}

void	init_plane(char **line_splited, t_object **world)
{
	t_vec3	point;
	t_vec3	vec;
	t_vec3	color;

	point = parse_point(line_splited[1]);
	vec = parse_vec(line_splited[2]);
	color = parse_rgb(line_splited[3]);
	oadd(world, object(PL, plane(point, vec), color));
}

void	init_sphere(char **line_splited, t_object **world)
{
	t_vec3		point;
	double		diameter;
	t_color3	color;

	point = parse_point(line_splited[1]);
	diameter = ft_atod(line_splited[2]);
	color = parse_rgb(line_splited[3]);
	oadd(world, object(SP, sphere(point, diameter), color));
}
