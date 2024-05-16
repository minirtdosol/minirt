/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:15:50 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/16 13:33:03 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_scene		t_scene;
typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_point3;
typedef struct s_vec3		t_color3;
typedef struct s_ray		t_ray;
typedef struct s_camera		t_camera;
typedef struct s_canvas		t_canvas;
typedef struct s_camera_set	t_camera_set;
typedef struct s_hit_record	t_hit_record;
typedef struct s_object		t_object;
typedef struct s_sphere		t_sphere;
typedef struct s_light		t_light;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_cylinops	t_cylinops;
typedef struct s_rotate		t_rotate;
typedef int					t_bool;
typedef int					t_object_type;
# define FALSE 0
# define TRUE 1
# define SP 0
# define PL 4
# define CY 5
# define LIGHT_POINT 1
# define EPSILON 1e-6
# define LUMEN 3

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
};

struct	s_camera_set
{
	t_vec3	lookat;
	t_vec3	vup;
	double	theta;
	double	viewport_w;
	double	viewport_h;
	double	half_width;
	t_vec3	w;
	t_vec3	u;
	t_vec3	v;
};

struct	s_rotate
{
	double	cos_a;
	double	cos_b;
	double	cos_r;
	double	sin_a;
	double	sin_b;
	double	sin_r;
	double	one_one;
	double	one_two;
	double	one_three;
	double	two_one;
	double	two_two;
	double	two_three;
	double	three_one;
	double	three_two;
	double	three_three;
};

struct s_camera
{
	t_point3	orig;
	double		viewport_h;
	double		viewport_w;
	t_vec3		horizontal;
	t_vec3		vertical;
	t_point3	left_bottom;
	t_vec3		dir;
	t_vec3		right_normal;
	t_vec3		up_normal;
	double		fov;
	double		focal_len;
};

struct s_cylinops
{
	double	hit_height;
};

struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
};

struct s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	t_color3		albedo;
};

struct s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
};

struct s_plane
{
	t_point3	center;
	t_vec3		dir;
};

struct s_cylinder
{
	t_point3	center;
	t_vec3		dir;
	t_vec3		bot;
	double		diameter;
	double		height;
	double		hit_height;
	t_point3	up;
	t_point3	down;
};

struct s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
};

struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
	t_color3	albedo;
};

struct s_scene
{
	t_canvas		canvas;
	t_camera		*camera;
	t_object		*world;
	t_object		*light;
	t_color3		ambient;
	t_ray			ray;
	t_hit_record	rec;
};

#endif