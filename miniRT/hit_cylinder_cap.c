/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_cap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:49:16 by soljeong          #+#    #+#             */
/*   Updated: 2024/05/16 14:52:51 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "trace.h"
#include "utils.h"

static void		hit_cylinder_rec(t_object *cy_obj, t_hit_record *rec, \
double height, t_ray *ray);
static float	calcul_root(t_object *cy_obj, t_ray *ray, \
double height, int *flag);

int	hit_cylinder_cap(t_object *cy_obj, t_ray *ray, \
t_hit_record *rec, double height)
{
	t_cylinder	*cy;
	t_vec3		circle_center;
	float		root;
	float		diameter;
	int			flag;

	flag = 1;
	cy = cy_obj->element;
	circle_center = vplus(cy->center, vmult(cy->dir, height));
	root = calcul_root(cy_obj, ray, height, &flag);
	if (flag == FALSE)
		return (FALSE);
	diameter = vlength(vminus(circle_center, ray_at(ray, root)));
	if (fabs((cy->diameter / 2)) < fabs(diameter))
		return (FALSE);
	if (root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	hit_cylinder_rec(cy_obj, rec, height, ray);
	return (1);
}

static float	calcul_root(t_object *cy_obj, t_ray *ray, \
double height, int *flag)
{
	t_cylinder	*cy;
	t_vec3		circle_center;
	float		down;
	float		up;

	cy = cy_obj->element;
	circle_center = vplus(cy->center, vmult(cy->dir, height));
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
	{
		flag = FALSE;
		return (0);
	}
	return (up / down);
}

static void	hit_cylinder_rec(t_object *cy_obj, t_hit_record *rec, \
double height, t_ray *ray)
{
	t_cylinder	*cy;

	cy = cy_obj->element;
	rec->tmax = rec->t;
	if (0 < height)
		rec->normal = cy->dir;
	else
		rec->normal = vmult(cy->dir, -1);
	set_face_normal(ray, rec);
	rec->albedo = cy_obj->albedo;
}
