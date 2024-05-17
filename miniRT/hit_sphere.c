/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokoh <dokoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:50:39 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/17 17:51:55 by dokoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

t_bool	hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec)
{
	t_sphere	*sp;
	t_cal		s;

	sp = sp_obj -> element;
	s.a = vlength2(ray -> dir);
	s.half_b = vdot(vminus(ray -> orig, sp -> center), ray->dir);
	s.discriminant = s.half_b * s.half_b - s.a * \
	(vlength2(vminus(ray -> orig, sp -> center)) - sp -> radius2);
	if (s.discriminant < 0)
		return (FALSE);
	s.root = (-s.half_b - sqrt(s.discriminant)) / s.a;
	if (s.root < rec -> tmin || rec -> tmax < s.root)
	{
		s.root = (-s.half_b + sqrt(s.discriminant)) / s.a;
		if (s.root < rec -> tmin || rec -> tmax < s.root)
			return (FALSE);
	}
	rec -> t = s.root;
	rec -> p = ray_at(ray, s.root);
	rec -> normal = vdivide(vminus(rec -> p, sp -> center), sp -> radius);
	set_face_normal(ray, rec);
	rec -> albedo = sp_obj -> albedo;
	return (TRUE);
}
