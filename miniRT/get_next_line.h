/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:36:50 by soljeong          #+#    #+#             */
/*   Updated: 2024/05/13 14:39:46 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# elif BUFFER_SIZE <= 0
#  error "is not valid BUFFER_SIZE"
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*buffer;
	int				read_buffer_size;
	int				buffer_idx;
	struct s_list	*next;
}	t_list;

t_list	*ft_search_fd(t_list **list, int fd);
t_list	*ft_lstnew_add_gnl(t_list **list, int fd);
void	*ft_lst_del_node_gnl(t_list **list, t_list *node);
char	*get_next_line(int fd);
char	*read_copy_line(t_list **list, t_list *node, int new_line);
int		search_copy_str(t_list *node, char *str, int *flag);
char	*ft_realloc_gnl(t_list *node, char *str, int str_len, int *str_malloc_size);
char	*ft_strdup_gnl(char *str, int str_len, t_list **list, t_list *node);
int		read_file(t_list *node, char *str, int flag);

#endif