/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 21:19:06 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/16 14:49:48 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "trace.h"
#include "utils.h"

double	cy_boundary(t_cylinder *cy, t_vec3 at_point)
{
	double	hit_height;
	double	max_height;

	hit_height = vdot(vminus(at_point, cy->down), cy -> dir);
	max_height = cy -> height;
	cy -> hit_height = hit_height;
	if (hit_height > max_height || hit_height < 0)
		return (0);
	return (hit_height);
}

t_vec3	get_cylinder_normal(t_cylinder *cy, t_vec3 at_point, double hit_height)
{
	t_point3	hit_center;
	t_vec3		normal;

	hit_center = vplus(cy -> down, vmult(cy -> dir, hit_height));
	normal = vminus(at_point, hit_center);
	return (vunit(normal));
}

t_bool	hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	int			result;
	t_vec3		height2;
	double		half_height;

	cy = cy_obj -> element;
	half_height = cy -> height / 2;
	height2 = vmult(cy -> dir, half_height);
	result = 0;
	cy -> up = vplus(cy -> center, height2);
	cy -> down = vminus(cy -> center, height2);
	result += hit_cylinder_cap(cy_obj, ray, rec, cy -> height / 2);
	result += hit_cylinder_cap(cy_obj, ray, rec, -(cy -> height / 2));
	result += hit_cylinder_side(cy_obj, ray, rec);
	return (result);
}
