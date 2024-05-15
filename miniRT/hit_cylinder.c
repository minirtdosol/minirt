/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokoh <dokoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 21:19:06 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/14 15:35:31 by dokoh            ###   ########.fr       */
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

int	hit_cylinder_cap(t_object *cy_obj, t_ray *ray, t_hit_record *rec, double height)
{
    const t_cylinder *cy = cy_obj->element;
    const double r = cy->diameter / 2;
	float down;
	float up; 
    const t_vec3    circle_center = vplus(cy->center, vmult(cy->dir, height));
	if (height > 0)
	{
		up = vdot(vminus(circle_center, ray -> orig), cy -> dir);
		down = vdot(ray -> dir, cy -> dir);
	}	
	else
	{
		up = vdot(vminus(circle_center, ray -> orig), vmult(cy -> dir, -1));
		down = vdot(ray -> dir, vmult(cy -> dir, -1));
	}
	if (down < EPSILON && down > -EPSILON)
		return (FALSE);
    const float root = up / down;
    const float diameter = vlength(vminus(circle_center, ray_at(ray, root)));
	if (fabs(r) < fabs(diameter))
	{
		return (0);
	}
    if (root < rec->tmin || rec->tmax < root)
       return (0);
    rec->t = root; 
    rec->p = ray_at(ray, root);
    rec->tmax = rec->t;
    if (0 < height)
        rec->normal = cy->dir;
    else
        rec->normal = vmult(cy->dir, -1);

    // rec->normal = vunit(vminus(circle_center, ray->origin)); // vmult(ray->dir, root)하면 안돼!!!
    set_face_normal(ray, rec);
    rec->albedo = cy_obj->albedo;
    return (1);
}

int	hit_cylinder_side(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	double a;
	double half_b;
	double c;
	t_vec3 h;
	t_vec3 w;
	t_vec3 v;
	t_vec3 o;
	double r;
	double discriminant;
	double sqrtd;
	double root;
	double hit_height;

	cy = cy_obj -> element; // 원기둥 구조체
	v = ray -> dir; // 광선의 방향 벡터
	o = cy -> dir; // 원기둥의 방향 벡터
	r = cy -> diameter / 2; // 원기둥의 반지름
	h = vunit(vminus(cy -> up, cy -> down));
	w = vminus(ray -> orig, cy -> down); // w식 Lo - 밑면의 원점

	a = vdot(v, v) - pow(vdot(v, h), 2);
	half_b = vdot(v, w) - (vdot(v, h) * vdot(w, h));
	c = vdot(w, w) - pow(vdot(w, h), 2) - pow(r, 2);
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec -> tmin || rec -> tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec -> tmin || rec -> tmax < root)
			return (FALSE);
	}
	if (!(hit_height = cy_boundary(cy, ray_at(ray, root))))
		return (0);
	rec -> t = root;
	rec -> p = ray_at(ray, root);
	rec -> normal = vunit(get_cylinder_normal(cy, rec -> p, hit_height));
	set_face_normal(ray, rec);
	rec -> albedo = cy_obj -> albedo;
	return (1);
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
	cy -> up = vplus(cy -> center, height2); // 원기둥 윗면의 원점
	cy -> down = vminus(cy -> center, height2); // 원기둥 밑면의 원점
	// if (ray -> orig > cy -> up)
	result += hit_cylinder_cap(cy_obj, ray, rec, cy -> height / 2);
	result += hit_cylinder_cap(cy_obj, ray, rec, -(cy -> height / 2));
	result += hit_cylinder_side(cy_obj, ray, rec);
	return (result);
}
