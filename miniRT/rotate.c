/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokoh <dokoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:31:44 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/15 19:37:45 by dokoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotate.h"

t_vec3	rotate(t_vec3 vec, t_rotate s)
{
	double	x;
	double	y;
	double	z;
	t_vec3	new;

	x = s.one_one * vec.x + s.one_two * vec.y + s.one_three * vec.z;
	y = s.two_one * vec.x + s.two_two * vec.y + s.two_three * vec.z;
	z = s.three_one * vec.x + s.three_two * vec.y + s.three_three * vec.z;
	new = vec3(x, y, z);
	return (new);
}


t_vec3	rotate_init(t_vec3 vec, double r, double b, double a)
{
	t_rotate	s;

	r = radian(r);
	b = radian(b);
	a = radian(a);
	s.cos_a = cos(a);
	s.cos_b = cos(b);
	s.cos_r = cos(r);
	s.sin_a = sin(a);
	s.sin_b = sin(b);
	s.sin_r = sin(r);
	s.one_one = s.cos_a * s.cos_b;
	s.one_two = s.cos_a * s.sin_b * s.sin_r - s.sin_a * s.cos_r;
	s.one_three = s.cos_a * s.sin_b * s.cos_r + s.sin_a * s.sin_r;
	s.two_one = s.sin_a * s.sin_b;
	s.two_two = s.sin_a * s.sin_b * s.sin_r + s.cos_a * s.cos_r;
	s.two_three = s.sin_a * s.sin_b * s.cos_r - s.cos_a * s.sin_r;
	s.three_one = -s.sin_b;
	s.three_two = s.cos_b * s.sin_r;
	s.three_three = s.cos_b * s.cos_r;
	return (rotate(vec, s));
}
