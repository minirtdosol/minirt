/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokoh <dokoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:33:18 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/13 18:37:02 by dokoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "structures.h"
# include "utils.h"

t_ray		ray(t_point3 orig, t_vec3 dir);
t_ray		ray_primary(t_camera *cam, double u, double v);
t_point3	ray_at(t_ray *ray, double t);
t_color3	ray_color(t_scene *scene);
t_bool		hit(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool		hit_plane(t_object *pl_obj, t_ray *ray, t_hit_record *rec);
void		set_face_normal(t_ray *r, t_hit_record *rec);
t_color3	phong_lighting(t_scene *scene);
t_color3	point_light_get(t_scene *scene, t_light *light);
t_bool		in_shadow(t_object *objs, t_ray light_ray, double light_len);
t_bool	hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec);
int	hit_cylinder_side(t_object *cy_obj, t_ray *ray, t_hit_record *rec);
int	hit_cylinder_cap(t_object *cy_obj, t_ray *ray, t_hit_record *rec, double height);
t_vec3	get_cylinder_normal(t_cylinder *cy, t_vec3 at_point, double hit_height);
double	cy_boundary(t_cylinder *cy, t_vec3 at_point);
#endif