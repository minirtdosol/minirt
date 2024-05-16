/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:20:53 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/16 15:09:59 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_bool	hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool			hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_anything = FALSE;
	while (world)
	{
		if (hit_obj(world, ray, &temp_rec))
		{
			hit_anything = TRUE;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		world = world -> next;
	}
	return (hit_anything);
}

t_bool	hit_obj(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (world -> type == SP)
		hit_result = hit_sphere(world, ray, rec);
	else if (world -> type == PL)
		hit_result = hit_plane(world, ray, rec);
	else if (world -> type == CY)
		hit_result = hit_cylinder(world, ray, rec);
	return (hit_result);
}
