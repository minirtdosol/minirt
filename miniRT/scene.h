/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokoh <dokoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:52:54 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/08 21:04:56 by dokoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

t_canvas	canvas(int width, int height);
t_camera	camera(t_canvas *canvas, t_point3 origin);
t_sphere	*sphere(t_point3 center, double radius);
t_object	*object(t_object_type type, void *element, t_color3 albedo);
t_light		*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio);

#endif