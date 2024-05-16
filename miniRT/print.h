/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:00:03 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/16 13:34:55 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdio.h>
# include "structures.h"

void	write_color(t_color3 pixel_color);
void	print_error(char *msg);
#endif