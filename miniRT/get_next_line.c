/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:13:27 by soljeong          #+#    #+#             */
/*   Updated: 2024/05/13 19:20:47 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*node;
	char			*str;

	if (fd < 0)
		return (NULL);
	node = ft_search_fd(&list, fd);
	if (!node)
		return (NULL);
	if (read(fd, 0, 0) == -1)
		return (ft_lst_del_node_gnl(&list, node));
	str = read_copy_line(&list, node, 0);
	return (str);
}

char	*read_copy_line(t_list **list, t_list *node, int new_line)
{
	char	*str;
	int		str_len;
	int		str_malloc_size;

	str_len = 0;
	str = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!str)
		return (ft_lst_del_node_gnl(list, node));
	str_malloc_size = BUFFER_SIZE;
	while (!new_line)
	{
		if (!read_file(node, str, str_len))
			return (ft_lst_del_node_gnl(list, node));
		if (str_len && node->read_buffer_size == 0)
		{
			ft_lst_del_node_gnl(list, node);
			return (ft_strdup_gnl(str, str_len, list, node));
		}
		str = ft_realloc_gnl(node, str, str_len, &str_malloc_size);
		if (!str)
			return (ft_lst_del_node_gnl(list, node));
		str_len += search_copy_str(node, &str[str_len], &new_line);
	}
	return (ft_strdup_gnl(str, str_len, list, node));
}

int	read_file(t_list *node, char *str, int str_len)
{
	if (node->buffer_idx < node->read_buffer_size)
		return (1);
	node->read_buffer_size = read(node->fd, node->buffer, BUFFER_SIZE);
	node->buffer_idx = 0;
	if (node->read_buffer_size < 0
		|| (node->read_buffer_size == 0 && !str_len))
	{
		free(str);
		return (0);
	}
	return (1);
}

int	search_copy_str(t_list *node, char *str, int *new_line)
{
	int		str_idx;

	str_idx = 0;
	while ((node->buffer_idx) < (node->read_buffer_size))
	{
		str[str_idx] = node->buffer[node->buffer_idx];
		if (str[str_idx] == '\n')
		{
			node->buffer_idx++;
			str[++str_idx] = '\0';
			*new_line = 1;
			return (str_idx);
		}
		node->buffer_idx += 1;
		str_idx++;
	}
	str[str_idx] = '\0';
	return (str_idx);
}

char	*ft_strdup_gnl(char *str, int str_len, t_list **list, t_list *node)
{
	char	*str2;
	int		i;

	str2 = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!str2)
	{
		free(str);
		ft_lst_del_node_gnl(list, node);
		return (0);
	}
	i = 0;
	while (str[i])
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	free(str);
	return (str2);
}
