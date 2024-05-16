/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:52:54 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/16 13:27:18 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

t_canvas	canvas(int width, int height);
void		camera(t_canvas *canvas, t_camera *cam);
t_camera	*camera_init(t_point3 orig, t_vec3 dir, double fov);
double		radian(double degrees);
t_sphere	*sphere(t_point3 center, double radius);
t_object	*object(t_object_type type, void *element, t_color3 albedo);
t_light		*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio);
t_plane		*plane(t_point3 center, t_vec3 dir);
t_cylinder	*cylinder(t_point3 center, t_vec3 dir, double dmt, double hgt);

#endif