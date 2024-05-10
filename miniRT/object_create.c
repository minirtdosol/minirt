/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokoh <dokoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:39:02 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/10 20:36:44 by dokoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "scene.h"

t_object	*object(t_object_type type, void *element, t_color3 albedo)
{
	t_object	*new;

	if (!(new = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	new -> type = type;
	new -> element = element;
	new -> next = NULL;
	new -> albedo = albedo;
	return (new);
}


t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere	*sp;

	if (!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sp -> center = center;
	sp -> radius = radius;
	sp -> radius2 = radius * radius;
	return (sp);
}

t_plane	*plane(t_point3 center, t_vec3 dir)
{
	t_plane	*pl;

	if (!(pl = (t_plane *)malloc(sizeof(t_plane))))
		return (NULL);
	pl -> center = center;
	dir = vunit(dir);
	pl -> dir = dir;
	return (pl);
}

t_light	*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio)
{
	t_light	*light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		return (NULL);
	light -> origin = light_origin;
	light -> light_color = light_color;
	light -> bright_ratio = bright_ratio;
	return (light);
}
