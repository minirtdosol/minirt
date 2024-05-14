/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:00:52 by soljeong          #+#    #+#             */
/*   Updated: 2023/10/17 19:12:02 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*head;
	void	*newcontent;

	if (!lst)
		return (0);
	head = 0;
	while (lst)
	{
		newcontent = f(lst -> content);
		node = ft_lstnew(newcontent);
		if (!node)
		{
			del(newcontent);
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, node);
		lst = lst -> next;
	}
	return (head);
}
