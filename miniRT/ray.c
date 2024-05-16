/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:34:42 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/16 13:15:37 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
// ray 생성자(정규화 된 ray)
t_ray	ray(t_point3 orig, t_vec3 dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vunit(dir);
	return (ray);
}

//ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점.
t_point3	ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = vplus(ray -> orig, vmult(ray -> dir, t));
	return (at);
}

t_hit_record	record_init(void)
{
	t_hit_record	record;

	//double 데이터 타입이 근사값이기 때문에 hit함수에서 t의 값이 0에 가까운 값이 나올 때, tmin이 0이면 비교 시
	//hit 상황이 아닐 때도 hit로 판단하는 오차를 만들어낼 수 있기 때문에 tmin값을 EPSILON으로 설정
	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

//primary_ray 생성자
t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.orig = cam -> orig;
	// left_bottom + u * horizontal + v * vectical - origin 의 단위 벡터.
	ray.dir = vunit(vminus(vplus(vplus(cam -> left_bottom, vmult(cam -> horizontal, u)), vmult(cam -> vertical, v)), cam -> orig));
	return (ray);
}


t_color3	ray_color(t_scene *scene)
{
	double			t;
	// t_vec3			n;

	//t는 광선 벡터의 크기인데 t가 음수 일 경우 카메라가 뒤에 있다는 것을 뜻한다.
	//tmin과 tmax는 각각 카메라가 뒤에 있거나 (t < 0), 카메라가 너무 멀 경우를 고려하기 위함이다.
	scene -> rec = record_init();
	if (hit(scene -> world, &scene -> ray, &scene -> rec))
		return (phong_lighting(scene));
	else
	{
		//ray의 방향벡터의 y 값을 기준으로 그라데이션을 주기 위한 계수.
		t = 0.5 * (scene -> ray.dir.y + 1.0);
		// (1-t) * 흰색 + t * 하늘색
		return (vplus(vmult(color3(1, 1, 1), 1.0 - t), vmult(color3(0.5, 0.7, 1.0), t)));
	}
}
