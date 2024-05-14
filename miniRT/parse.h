/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:42:40 by soljeong          #+#    #+#             */
/*   Updated: 2024/05/13 18:45:47 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
#include <stdlib.h>
#include "structures.h"
#define FAIL 0
#define SUCCESS 1
#define ERROR 2

int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	is_rt_file(char *filename);
int	parse_rt(int fd, t_scene *scene);
#endif