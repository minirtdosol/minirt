/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:39:02 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/17 12:16:20 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "scene.h"

t_object	*object(t_object_type type, void *element, t_color3 albedo)
{
	t_object	*new;

	new = (t_object *)malloc(sizeof(t_object));
	if (!new)
		exit (1);
	new -> type = type;
	new -> element = element;
	new -> next = NULL;
	new -> albedo = albedo;
	return (new);
}

t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere	*sp;

	sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sp)
		exit (1);
	sp -> center = center;
	sp -> radius = radius;
	sp -> radius2 = radius * radius;
	return (sp);
}

t_plane	*plane(t_point3 center, t_vec3 dir)
{
	t_plane	*pl;

	pl = (t_plane *)malloc(sizeof(t_plane));
	if (!pl)
		exit (1);
	pl -> center = center;
	dir = vunit(dir);
	pl -> dir = dir;
	return (pl);
}

t_cylinder	*cylinder(t_point3 center, t_vec3 dir, double dmt, double hgt)
{
	t_cylinder	*cy;

	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cy)
		exit (1);
	cy -> center = center;
	dir = vunit(dir);
	cy -> dir = dir;
	cy -> diameter = dmt;
	cy -> height = hgt;
	return (cy);
}

t_light	*light_point(t_point3 light_origin, \
t_color3 light_color, double bright_ratio)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		exit (1);
	light -> origin = light_origin;
	light -> light_color = light_color;
	light -> bright_ratio = bright_ratio;
	return (light);
}
