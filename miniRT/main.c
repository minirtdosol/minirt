/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:02:13 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/16 15:12:45 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "print.h"
#include "scene.h"
#include "trace.h"
#include "parse.h"
#include <fcntl.h>
#include <unistd.h>
#include "rotate.h"

t_scene	*scene_init(int fd)
{
	t_scene		*scene;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	scene -> canvas = canvas(1000, 1000);
	parse_rt(fd, scene);
	camera(&scene -> canvas, scene -> camera);
	return (scene);
}
int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	main(int argc, char *argv[])
{
	int			i;
	int			j;
	double		u;
	double		v;
	void		*mlx_ptr;
	void		*win_ptr;
	t_color3	pixel_color;
	t_scene		*scene;
	int x;
	int y;
	int z;
	int	fd;

	if (argc !=2 || is_rt_file(argv[1]) == FAIL)
		print_error(": Wrong arguments");
	fd = open(argv[1],O_RDONLY);
	if (fd < 0)
	{
		perror("Error\n");
		exit(1);
	}
	scene = scene_init(fd);
	close(fd);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, scene -> canvas.width, scene -> canvas.height, "Hellow World!");
	
	// 랜더링
	// P3는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
	// printf("P3\n%d %d\n255\n", scene -> canvas.width, scene -> canvas.height);
	j = scene -> canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < scene -> canvas.width)
		{
			u = (double)i / (scene -> canvas.width - 1);
			v = (double)j / (scene -> canvas.height - 1);
			//ray from camera origin to pixel;
			scene -> ray = ray_primary(scene -> camera, u, v);
			pixel_color = ray_color(scene);
			// write_color(pixel_color);
			x = (int)(pixel_color.x * 255.999);
			y = (int)(pixel_color.y * 255.999);
			z = (int)(pixel_color.z * 255.999);
			mlx_pixel_put(mlx_ptr, win_ptr, i, scene -> canvas.height - 1 - j, create_trgb(0, x, y, z));
			i++;
		}
		--j;
 	}
	mlx_loop(mlx_ptr);
	return (0);
}
