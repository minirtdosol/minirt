/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:50:39 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/16 15:09:22 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

t_bool	hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec)
{
	t_sphere	*sp;
	double		a;
	double		half_b;
	double		discriminant;
	double		root;

	sp = sp_obj -> element;
	a = vlength2(ray -> dir);
	half_b = vdot(vminus(ray -> orig, sp -> center), ray->dir);
	discriminant = half_b * half_b - a * \
	(vlength2(vminus(ray -> orig, sp -> center)) - sp -> radius2);
	if (discriminant < 0)
		return (FALSE);
	root = (-half_b - sqrt(discriminant)) / a;
	if (root < rec -> tmin || rec -> tmax < root)
		return (FALSE);
	rec -> t = root;
	rec -> p = ray_at(ray, root);
	rec -> normal = vdivide(vminus(rec -> p, sp -> center), sp -> radius);
	set_face_normal(ray, rec);
	rec -> albedo = sp_obj -> albedo;
	return (TRUE);
}
