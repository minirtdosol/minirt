/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:02:13 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/17 12:16:06 by soljeong         ###   ########.fr       */
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
#include "mlx_data.h"

t_scene	*scene_init(int fd)
{
	t_scene		*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		exit (1);
	scene -> canvas = canvas(1000, 1000);
	parse_rt(fd, scene);
	camera(&scene -> canvas, scene -> camera);
	return (scene);
}

int	main(int argc, char *argv[])
{
	t_scene		*scene;
	t_data		data;
	int			fd;

	if (argc != 2 || is_rt_file(argv[1]) == FAIL)
		print_error(": Wrong arguments");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error\n");
		exit(1);
	}
	scene = scene_init(fd);
	close(fd);
	my_mlx_init(&data, scene);
	draw_minirt(scene, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, exit_hook, 0);
	mlx_loop(data.mlx);
	return (0);
}
