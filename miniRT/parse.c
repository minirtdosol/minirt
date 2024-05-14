/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:10:53 by soljeong          #+#    #+#             */
/*   Updated: 2024/05/14 13:32:52 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include "get_next_line.h"
# include "libft/libft.h"
# include "parse.h"
# include "print.h"
# include "utils.h"
#include "structures.h"
#include "scene.h"


void	init_ambient(char **line_splited, t_scene *scene);
void	init_light(char **line_splited, t_scene *scene);
void	init_cylinder(char **line_splited, t_object **world);
void	splited_free(char **splited);
void	init_sphere(char **line_splited, t_object **world);
void	init_plane(char **line_splited, t_object **world);

int	parse_rt(int fd, t_scene *scene)
{
	char	*str;
	char	**splited;

	scene->world = NULL;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break;
		if (str[0] == '#' || str[0] == '\n')
			continue;
		splited = ft_split(str, ' ');
		if (ft_strncmp(splited[0],"A",2) == 0)
			init_ambient(splited, scene);
		else if (ft_strncmp(splited[0], "C", 2) == 0)
		{
			//Camera
			// splited[1]은 x,y,z (쉼표로 구분)
			// splited[1] 3d normalized orientation vector x,y,z(쉼표로 구분) -1 ~ 1 사이
			// FOV 0 ~ 180
		}
		else if (ft_strncmp(splited[0], "L", 2) == 0)
			init_light(splited, scene);
		else if (ft_strncmp(splited[0], "cy", 3) == 0)
			init_cylinder(splited, &(scene->world));
		else if (ft_strncmp(splited[0], "sp", 3) == 0)
			init_sphere(splited, &(scene->world));
		else if (ft_strncmp(splited[0], "pl", 3) == 0)
			init_plane(splited, &(scene->world));
		else
			print_error("Wrong content in .rt file");
		splited_free(splited);
	}
	return (0);
}

void	splited_free(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}


