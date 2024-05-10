/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokoh <dokoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:15:50 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/10 17:55:34 by dokoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
//전체 구조체
typedef struct s_scene	t_scene;
//벡터 구조체
typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_color3;
//광선 구조체
typedef struct s_ray	t_ray;
// 장면 구조체
typedef struct s_camera	t_camera;
typedef struct s_canvas	t_canvas;
// 오브젝트 구조체
typedef struct s_hit_record t_hit_record;
typedef struct s_object	t_object;
typedef struct s_sphere	t_sphere;
typedef struct s_light	t_light;
typedef struct s_plane	t_plane;
//식별자 매크로
typedef int				t_bool;
# define FALSE 0
# define TRUE 1
typedef int		t_object_type;
# define SP 0
# define PL 4
# define CY 5
# define LIGHT_POINT 1
# define EPSILON 1e-6 // 0.0000001
# define LUMEN 3 // 이 값을 조절하여 장면의 밝기를 조절할 수 있다.

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

struct s_camera
{
	t_point3	orig; // 카메라 원점(위치)
	double		viewport_h; // 뷰포트 세로 길이
	double		viewport_w; // 뷰포트 가로 길이
	t_vec3		horizontal; // 수평 길이 벡터
	t_vec3		vertical; // 수직 길이 벡터
	double		focal_len; // 카메라와 뷰포트 사이의 거리
	t_point3	left_bottom; // 왼쪽 아래 코너점
};

struct s_plane
{
	t_point3	center; // 평면의 중심
	t_vec3		dir; // 평면이 가리키는 방향
};

struct s_canvas
{
	int		width; //canvas width
	int		height; // canvas height;
	double	aspect_ratio; // 종횡비
};

// 오브젝트 구조체
struct s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	t_color3		albedo;
};
// 구 구조체
struct s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
};

struct s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
};


struct s_hit_record
{
	t_point3	p; //교점의 좌표
	t_vec3		normal; // 교점에서의 법선
	double		tmin; 
	double		tmax;
	double		t; // 광선의 원점과 교점 사이의 거리
	t_bool		front_face;
	t_color3	albedo;
};

struct s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_color3		ambient;
	t_ray			ray;
	t_hit_record	rec;
};

#endif