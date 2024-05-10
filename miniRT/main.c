/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokoh <dokoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:02:13 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/09 21:01:53 by dokoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "print.h"
#include "scene.h"
#include "trace.h"

t_scene	*scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;
	double		ka;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	scene -> canvas = canvas(1000, 1000);
	scene -> camera = camera(&scene -> canvas, point3(0, 0, 0));
	world = object(SP, sphere(point3(1, 0, -7), 1), color3(0.5, 0, 0));
	oadd(&world, object(SP, sphere(point3(0, 0, -5), 1), color3(0, 0.5, 0)));
	oadd(&world, object(SP, sphere(point3(0, -1000, 0), 999), color3(1, 1, 1)));
	scene -> world = world;
	lights = object(LIGHT_POINT, light_point(point3(0, 5, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0)); //더미 albedo
	scene->light = lights;
	ka = 0.1;
	scene->ambient = vmult(color3(1, 1, 1), ka);
	//ambient는 ambient lighting의 색과 ambient lighting의 강도(ambient strength) 계수인
	//ka의 곱으로 표현된다. ka 값은 장면의 원하는 밝기에 따라 [0 ~ 1] 사이의 값으로 설정하면 된다.
	return (scene);
}
int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;
	
	dst = data -> addr + (y * data -> line_length + x * (data -> bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	int			i;
	int			j;
	double		u;
	double		v;
	void		*mlx_ptr;
	void		*win_ptr;
	t_color3	pixel_color;
	t_scene		*scene;
	t_data		image;
	int x;
	int y;
	int z;

	scene = scene_init();
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, scene -> canvas.width, scene -> canvas.height, "Hellow World!");
	image.img = mlx_new_image(mlx_ptr, scene -> canvas.width, scene -> canvas.height);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	// 랜더링
	// P3는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
	printf("P3\n%d %d\n255\n", scene -> canvas.width, scene -> canvas.height);
	j = scene -> canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < scene -> canvas.width)
		{
			u = (double)i / (scene -> canvas.width - 1);
			v = (double)j / (scene -> canvas.height - 1);
			//ray from camera origin to pixel;
			scene -> ray = ray_primary(&scene -> camera, u, v);
			pixel_color = ray_color(scene);
			x = (int)(pixel_color.x * 255.999);
			y = (int)(pixel_color.y * 255.999);
			z = (int)(pixel_color.z * 255.999);
			mlx_pixel_put(mlx_ptr, win_ptr, i, scene -> canvas.height - 1 - j, create_trgb(0, x, y, z));
			write_color(pixel_color);
			i++;
		}
		--j;
 	}
	mlx_loop(mlx_ptr);
	return (0);
}