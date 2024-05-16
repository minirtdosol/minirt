/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:42:40 by soljeong          #+#    #+#             */
/*   Updated: 2024/05/14 19:20:01 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
#include <stdlib.h>
#include "structures.h"
#define FAIL 0
#define SUCCESS 1
#define ERROR 2

enum {
	AMBIENT,
	CAMERA,
	LIGHT
};

int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	is_rt_file(char *filename);
int	parse_rt(int fd, t_scene *scene);
void	init_cylinder(char **line_splited, t_object **world);
void	init_plane(char **line_splited, t_object **world);
void	init_sphere(char **line_splited, t_object **world);
void	init_ambient(char **line_splited, t_scene *scene);
void	init_light(char **line_splited, t_scene *scene);
t_vec3	parse_vec3(char *str);
t_color3	parse_rgb(char *str);
t_vec3	parse_vec(char *str);
t_point3	parse_point(char *str);
void	splited_free(char **splited);
void	init_camera(char **line_splited, t_scene *scene);
void	init_acl(char **line_splited, t_scene *scene, int *acl, int acl_num);

#endif