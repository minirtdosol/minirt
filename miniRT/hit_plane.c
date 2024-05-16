/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:44:51 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/16 15:00:41 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

t_bool	hit_plane(t_object *pl_obj, t_ray *ray, t_hit_record *rec)
{
	t_plane	*pl;
	float	down;
	float	up;
	float	root;

	pl = pl_obj -> element;
	down = vdot(ray -> dir, pl -> dir);
	if (down < EPSILON && down > -EPSILON)
		return (FALSE);
	up = vdot(vminus(pl -> center, ray -> orig), pl -> dir);
	root = up / down;
	if (root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec -> t = root;
	rec -> p = ray_at(ray, root);
	rec -> albedo = pl_obj -> albedo;
	return (TRUE);
}
