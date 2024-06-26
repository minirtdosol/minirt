/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:25:40 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/16 13:35:12 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATE_H
# define ROTATE_H

# include <math.h>
# include "structures.h"
# include "utils.h"
# include "scene.h"

t_vec3	rotate(t_vec3 vec, t_rotate s);
t_vec3	rotate_init(t_vec3 vec, double a, double b, double r);
#endif