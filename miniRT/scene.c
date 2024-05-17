/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:57:08 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/17 12:16:29 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

double	radian(double degrees)
{
	return (degrees * M_PI / 180.0);
}

t_camera	*camera_init(t_point3 orig, t_vec3 dir, double fov)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		exit (1);
	camera -> orig = orig;
	vunit(dir);
	camera -> dir = dir;
	camera -> fov = fov;
	return (camera);
}

void	camera(t_canvas *canvas, t_camera *cam)
{
	t_camera_set	save;

	if (cam -> dir.x == 0 && cam -> dir.z == 0)
		cam -> dir.z = EPSILON;
	save.lookat = vplus(cam -> orig, vmult(cam -> dir, -1));
	save.vup = vec3(0.0, 1.0, 0.0);
	save.theta = radian(cam -> fov);
	save.half_width = tan(save.theta / 2);
	save.viewport_w = 2 * save.half_width;
	save.viewport_h = save.viewport_w / canvas -> aspect_ratio;
	save.w = vunit(cam -> dir);
	save.u = vunit(vcross(save.vup, save.w));
	save.v = vcross(save.w, save.u);
	cam -> horizontal = vmult(save.u, save.viewport_w);
	cam -> vertical = vmult(save.v, save.viewport_h);
	cam -> left_bottom = vminus(vminus(save.lookat, \
	vdivide(cam -> horizontal, 2)), vdivide(cam -> vertical, 2));
}
