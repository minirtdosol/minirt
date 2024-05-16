/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_side.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:44:31 by soljeong          #+#    #+#             */
/*   Updated: 2024/05/16 14:54:30 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "trace.h"
#include "utils.h"

static double	make_a(t_ray *ray, t_cylinder *cy);
static double	make_harf_b(t_ray *ray, t_cylinder *cy);
static double	make_c(t_ray *ray, t_cylinder *cy);

int	hit_cylinder_side(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	double	a;
	double	half_b;
	double	discriminant;
	double	root;
	double	hit_height;

	a = make_a(ray, cy_obj -> element);
	half_b = make_harf_b(ray, cy_obj->element);
	discriminant = half_b * half_b - a * make_c(ray, cy_obj->element);
	if ((discriminant) < 0)
		return (FALSE);
	root = (-half_b - sqrt((discriminant))) / a;
	if (root < rec -> tmin || rec -> tmax < root)
		return (FALSE);
	hit_height = cy_boundary(cy_obj->element, ray_at(ray, root));
	if (!(hit_height))
		return (0);
	rec -> t = root;
	rec -> p = ray_at(ray, root);
	rec -> normal = vunit(get_cylinder_normal(cy_obj->element, \
	rec -> p, hit_height));
	set_face_normal(ray, rec);
	rec -> albedo = cy_obj -> albedo;
	return (1);
}

static double	make_a(t_ray *ray, t_cylinder *cy)
{
	t_vec3		v;
	t_vec3		h;

	v = ray -> dir;
	h = vunit(vminus(cy -> up, cy -> down));
	return (vdot(v, v) - pow(vdot(v, h), 2));
}

static double	make_harf_b(t_ray *ray, t_cylinder *cy)
{
	t_vec3		v;
	t_vec3		h;
	t_vec3		w;

	w = vminus(ray -> orig, cy -> down);
	v = ray -> dir;
	h = vunit(vminus(cy -> up, cy -> down));
	return (vdot(v, w) - (vdot(v, h) * vdot(w, h)));
}

static double	make_c(t_ray *ray, t_cylinder *cy)
{
	t_vec3		v;
	t_vec3		h;
	t_vec3		w;

	w = vminus(ray -> orig, cy -> down);
	v = ray -> dir;
	h = vunit(vminus(cy -> up, cy -> down));
	return (vdot(w, w) - pow(vdot(w, h), 2) - pow((cy -> diameter / 2), 2));
}
