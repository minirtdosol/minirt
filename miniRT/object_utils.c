/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokoh <dokoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:39:31 by dokoh             #+#    #+#             */
/*   Updated: 2024/05/08 19:43:12 by dokoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	oadd(t_object **list, t_object *new)
{
	t_object	*cur;

	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	cur = *list;
	while (cur -> next)
		cur = cur -> next;
	cur -> next = new;
}

t_object	*olast(t_object *list)
{
	if (list == NULL)
		return (NULL);
	while (list-> next)
		list = list -> next;
	return (list);
}