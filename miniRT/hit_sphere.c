/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokoh <dokoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:50:39 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/13 19:09:39 by dokoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

t_bool	hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec)
{
	// a, b, c는 각각 t에 관한 2차 방정식의 계수
	t_sphere	*sp;
	t_vec3	oc; // 방향벡터로 나타낸 구의 중심
	double	a;
	double	half_b;
	double	c;
	double	discriminant; // 판별식
	double	sqrtd;
	double	root;

	sp = sp_obj -> element;
	oc = vminus(ray -> orig, sp -> center);
	a = vlength2(ray -> dir);
	half_b = vdot(oc, ray->dir);
	c = vlength2(oc) - sp -> radius2;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	// 두 실근(t) 중 tmin과 tmax 사이에 있는 근이 있는지 체크, 작은 근부터 체크
	root = (-half_b - sqrtd) / a; // 두 근(t) 중 작은 근(t)부터 고려.
	if (root < rec -> tmin || rec -> tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec -> tmin || rec -> tmax < root)
			return (FALSE);
	}
	rec -> t = root;
	rec -> p = ray_at(ray, root);
	//정규화된 법선 벡터
	rec -> normal = vdivide(vminus(rec -> p, sp -> center), sp -> radius);
	//rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool 값으로 저장
	// 구가 카메라를 둘러싸고 있는 경우를 고려하기 위함이다. 카메라가 구 안쪽에 있다면 광선과 법선은 같은 방향을 향하게 될 것이다.
	// 그러나 오브젝트와 광원 간의 상호작용을 계산하기 위해서는 법선과 광선이 항상 반대 방향을 향하고 있어야 한다.
	set_face_normal(ray, rec);
	rec -> albedo = sp_obj -> albedo;
	return (TRUE);
}
