/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:57:08 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/14 16:08:22 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#define	WIDTH 1000
#define	HEIGHT 1000

double	get_tan(double degree)
{
	static const double radian = M_PI / 180;
	return (tan(degree * radian));
}

t_camera	camera(t_canvas *canvas, t_point3 orig, t_vec3 dir, double fov)
{
	t_camera    cam;
    t_vec3      vec_y;
    t_vec3      vec_z;
    t_vec3      temp;
	(void)canvas;
    
    vec_y = vec3(0.0, 1.0, 0.0);
    vec_z = vec3(0.0, 0.0, -1.0);
    
    cam.orig = orig;
    cam.dir = dir;
    cam.fov = fov;
    if (vlength(vcross(vec_y, cam.dir)))
        cam.right_normal = vunit(vcross(cam.dir, vec_y));
    else 
        cam.right_normal = vunit(vcross(cam.dir, vec_z));
    cam.up_normal = vunit(vcross(cam.right_normal, cam.dir));
    cam.focal_len = WIDTH / 2 / get_tan(cam.fov / 2);

    temp = vplus(cam.orig, vmult(cam.dir, cam.focal_len));
    temp = vminus(temp, vmult(cam.right_normal, -(WIDTH - 1)/ 2));
    temp = vminus(temp, vmult(cam.up_normal,-(HEIGHT - 1)/ 2));
    cam.left_bottom = temp;
    // print_vec(cam.right_normal);
    // print_vec(cam.up_normal);
    // print_vec(cam.left_bottom);
    return (cam);
}