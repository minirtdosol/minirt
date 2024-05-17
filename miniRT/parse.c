/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokoh <dokoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:10:53 by soljeong          #+#    #+#             */
/*   Updated: 2024/05/17 13:40:06 by dokoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include "libft/libft.h"
#include "parse.h"
#include "print.h"
#include "utils.h"
#include "structures.h"
#include "scene.h"

static void	init_arg(char **splited, t_scene *scene, int *acl);
static void	check_acl(int *acl);

int	parse_rt(int fd, t_scene *scene)
{
	char	*str;
	char	**splited;
	int		acl[3];

	scene->world = NULL;
	acl[0] = 0;
	acl[1] = 0;
	acl[2] = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		if (str[0] == '#' || str[0] == '\n')
		{
			free(str);
			continue ;
		}
		splited = ft_split(str, ' ');
		init_arg(splited, scene, acl);
		splited_free(splited);
		free(str);
	}
	check_acl(acl);
	return (0);
}

static void	check_acl(int *acl)
{
	if (!acl[0] || !acl[1] || !acl[2])
	{
		print_error("Worng in rt file");
		exit(1);
	}
}

static void	init_arg(char **splited, t_scene *scene, int *acl)
{
	if (splited == NULL || *splited == NULL)
		print_error("Wrong in file");
	if (ft_strncmp(splited[0], "A", 2) == 0)
		init_acl(splited, scene, acl, AMBIENT);
	else if (ft_strncmp(splited[0], "C", 2) == 0)
		init_acl(splited, scene, acl, CAMERA);
	else if (ft_strncmp(splited[0], "L", 2) == 0)
		init_acl(splited, scene, acl, LIGHT);
	else if (ft_strncmp(splited[0], "cy", 3) == 0)
		init_cylinder(splited, &(scene->world));
	else if (ft_strncmp(splited[0], "sp", 3) == 0)
		init_sphere(splited, &(scene->world));
	else if (ft_strncmp(splited[0], "pl", 3) == 0)
		init_plane(splited, &(scene->world));
	else
		print_error("Wrong content in .rt file");
}

void	splited_free(char **splited)
{
	int	i;

	i = 0;
	if (splited == NULL || *splited == NULL)
		return ;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

int	splited_len(char **splited)
{
	int	i;

	i = 0;
	if (splited == NULL || *splited == NULL)
		return (0);
	while (splited[i])
	{
		i++;
	}
	return (i);
}
