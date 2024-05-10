/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokoh <dokoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:31:35 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/09 20:46:47 by dokoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//벡터3 생성자
t_vec3	vec3(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

//포인터3 생성자
t_point3	point3(double x, double y, double z)
{
	t_point3	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

//색상3 생성자
t_color3	color3(double r, double g, double b)
{
	t_color3	color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}

//벡터 값 설정
void	vset(t_vec3 *vec, double x, double y, double z)
{
	vec -> x = x;
	vec -> y = y;
	vec -> z = z;
}

//벡터 길이 제곱
double	vlength2(t_vec3 vec)
{
	return (vec.x * vec.x + vec.y *vec.y + vec.z * vec.z);
}

// 벡터 길이
double	vlength(t_vec3 vec)
{
	return (sqrt(vlength2(vec)));
}

//벡터합
t_vec3	vplus(t_vec3 vec, t_vec3 vec2)
{
	vec.x += vec2.x;
	vec.y += vec2.y;
	vec.z += vec2.z;
	return (vec);
}

// 벡터합2
t_vec3 vplus_(t_vec3 vec, double x, double y, double z)
{
	vec.x += x;
	vec.y += y;
	vec.z += z;
	return (vec);
}

//벡터차
t_vec3	vminus(t_vec3 vec, t_vec3 vec2)
{
	vec.x -= vec2.x;
	vec.y -= vec2.y;
	vec.z -= vec2.z;
	return (vec);
}
//벡터차2
t_vec3	vminus_(t_vec3 vec, double x, double y, double z)
{
	vec.x -= x;
	vec.y -= y;
	vec.z -= z;
	return (vec);
}
//벡터 * 스칼라 곱연산
t_vec3	vmult(t_vec3 vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}
// 벡터 축 값끼리 곱연산
t_vec3	vmult_(t_vec3 vec, t_vec3 vec2)
{
	vec.x *= vec2.x;
	vec.y *= vec2.y;
	vec.z *= vec2.z;
	return (vec);
}

// 벡터 스칼라 나누기
t_vec3	vdivide(t_vec3 vec, double t)
{
	vec.x *= 1 / t;
	vec.y *= 1 / t;
	vec.z *= 1 / t;
	return (vec);
}
// 벡터 내적
// 내적 사용 이유 : 3D상에서는 축이 돌아갈 수도 있기 때문에 밑변의 길이를 알기 어려울 때 내적을 사용한다.
double	vdot(t_vec3 vec, t_vec3 vec2)
{
	return (vec.x * vec2.x + vec.y * vec2.y + vec.z * vec2.z);
}

//벡터 외적
//외적 사용 이유 : 두 벡터의 수직인 벡터가 결과로 나온다.
//1. 앞면과 뒷면을 알 수 있다.

t_vec3	vcross(t_vec3 vec, t_vec3 vec2)
{
	t_vec3	new;

	new.x = vec.y * vec2.z - vec.z * vec2.y;
	new.y = vec.z * vec2.x - vec.x * vec2.z;
	new.z = vec.x * vec2.y - vec.y * vec2.x;
	return (new);
}

//단위 벡터 : 크기가 1인 벡터
//벡터의 길이를 나누면 된다.
//벡터의 방향을 알고 싶을 때
t_vec3	vunit(t_vec3 vec)
{
	double	len;

	len = vlength(vec);
	if (len == 0)
	{
		printf("Error:Devider is 0\n");
		exit(0);
	}
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}

//두 벡터의 원소를 비교하여 작은 값들만 반환
t_vec3	vmin(t_vec3 vec1, t_vec3 vec2)
{
	if (vec1.x > vec2.x)
		vec1.x = vec2.x;
	if (vec1.y > vec2.y)
		vec1.y = vec2.y;
	if (vec1.z > vec2.z)
		vec1.z = vec2.y;
	return (vec1);
}
