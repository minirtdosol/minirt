/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:43:00 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/16 15:15:16 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec -> front_face = vdot(r -> dir, rec -> normal) < 0;
	if (rec -> front_face)
		rec -> normal = rec -> normal;
	else
		rec->normal = vmult(rec->normal, -1);
}
