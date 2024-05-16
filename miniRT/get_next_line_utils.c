/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:32:55 by soljeong          #+#    #+#             */
/*   Updated: 2024/05/16 15:39:30 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew_add_gnl(t_list **list, int fd)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->fd = fd;
	node->next = *list;
	node->buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(node->buffer))
	{
		free(node);
		return (NULL);
	}
	node->read_buffer_size = 0;
	node->buffer_idx = 0;
	*list = node;
	return (node);
}

t_list	*ft_search_fd(t_list **list, int fd)
{
	t_list	*node;

	node = *list;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node -> next;
	}
	node = ft_lstnew_add_gnl(list, fd);
	return (node);
}

char	*ft_realloc_gnl(t_list *node, char *str, \
int str_len, int *str_malloc_size)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = 0;
	if (*str_malloc_size - str_len <= node->read_buffer_size)
	{
		tmp = (char *)malloc(sizeof(char) * ((*str_malloc_size) * 2));
		if (!tmp)
		{
			free(str);
			return (0);
		}
		while (i < str_len)
		{
			tmp[i] = str[i];
			i++;
		}
		tmp[i] = '\0';
		if (str)
			free(str);
		(*str_malloc_size) *= 2;
		return (tmp);
	}
	return (str);
}

void	*ft_lst_del_node_gnl(t_list **list, t_list *node)
{
	t_list	*prev;
	t_list	*curr;

	curr = *list;
	prev = NULL;
	if (!*list)
		return (0);
	while (curr)
	{
		if (curr->fd == node->fd)
		{
			if (prev)
				prev->next = curr->next;
			else
				*list = curr->next;
			free(curr->buffer);
			free(curr);
			return (0);
		}
		prev = curr;
		curr = curr->next;
	}
	return (0);
}
