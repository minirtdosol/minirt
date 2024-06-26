/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:04:56 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/16 15:29:05 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "stdlib.h"

void	write_color(t_color3 pixel_color)
{
	printf("%d %d %d\n", (int)(255.999 * pixel_color.x), \
	(int)(255.999 * pixel_color.y), \
	(int)(255.999 * pixel_color.z));
}

void	print_error(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(1);
}
