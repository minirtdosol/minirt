/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:04:57 by soljeong          #+#    #+#             */
/*   Updated: 2024/05/16 16:59:00 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DATA_H
# define MLX_DATA_H
# include "scene.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int		key_hook(int keycode, t_data *data);
void	my_mlx_init(t_data *data, t_scene *scene);
void	draw_minirt(t_scene *scene, t_data *data);
int		exit_hook(void);

#endif