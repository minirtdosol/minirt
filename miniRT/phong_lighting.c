/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:43:22 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/16 15:28:33 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include <stdio.h>

t_bool	in_shadow(t_object *objs, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(objs, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (vminus(v, vmult(n, vdot(v, n) * 2)));
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_color3	diffuse;
	t_vec3		light_dir;
	t_color3	specular;
	t_vec3		view_dir;
	t_vec3		reflect_dir;

	light_dir = vminus(light -> origin, scene -> rec.p);
	if (in_shadow(scene->world, ray(vplus(scene -> rec.p, \
	vmult(scene->rec.normal, EPSILON)), light_dir), vlength(light_dir)))
		return (color3(0, 0, 0));
	light_dir = vunit(light_dir);
	view_dir = vunit(vmult(scene->ray.dir, -1));
	diffuse = vmult(light -> light_color, \
	fmax(vdot(scene->rec.normal, light_dir), 0.0));
	reflect_dir = reflect(vmult(light_dir, -1), scene -> rec.normal);
	specular = vmult(vmult(light->light_color, 0.5), \
	pow(fmax(vdot(view_dir, reflect_dir), 0.0), 64));
	return (vmult(vplus(diffuse, specular), light -> bright_ratio * LUMEN));
}

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;

	light_color = color3(0, 0, 0);
	lights = scene -> light;
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
			light_color = vplus(light_color, \
			point_light_get(scene, lights -> element));
		lights = lights -> next;
	}
	light_color = vplus(light_color, scene -> ambient);
	return (vmin(vmult_(light_color, scene -> rec.albedo), color3(1, 1, 1)));
}
