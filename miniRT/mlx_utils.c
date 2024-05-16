/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:00:48 by soljeong          #+#    #+#             */
/*   Updated: 2024/05/16 16:56:15 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "print.h"
#include "scene.h"
#include "trace.h"
#include "parse.h"
#include "mlx_data.h"

void	draw_minirt(t_scene *scene, t_data *data)
{
	int			i;
	int			j;
	t_color3	pixel_color;

	j = scene -> canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < scene -> canvas.width)
		{
			scene -> ray = ray_primary(scene -> camera, \
			(double)i / (scene -> canvas.width - 1), \
			(double)j / (scene -> canvas.height - 1));
			pixel_color = ray_color(scene);
			mlx_pixel_put(data->mlx, data->win, i, \
			scene -> canvas.height - 1 - j, \
			create_trgb(0, (int)(pixel_color.x * 255.999), \
			(int)(pixel_color.y * 255.999), \
			(int)(pixel_color.z * 255.999)));
			i++;
		}
		--j;
	}
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

void	my_mlx_init(t_data *data, t_scene *scene)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->win = mlx_new_window(data->mlx, \
	scene->canvas.width, scene->canvas.width, "miniRT");
	if (!data->win)
		exit(1);
	data->img = mlx_new_image(data->mlx, \
	scene->canvas.width, scene->canvas.width);
	if (!data->img)
		exit(1);
	data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel), \
	&data->line_length, &data->endian);
	if (!data->addr)
		exit(1);
}

int	exit_hook(void)
{
	exit(0);
}
