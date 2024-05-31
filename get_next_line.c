/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:22:05 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/05/30 16:39:41 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_append(t_list **list, char *buffer)
{
	t_list	*newnode;
	t_list	*lastnode;

	lastnode = ft_lastnode(*list);
	newnode = malloc(sizeof(t_list));
	if (NULL == newnode)
		return ;
	if (NULL == lastnode)
		*list = newnode;
	else
		lastnode->next = newnode;
	newnode->content = buffer;
	newnode->next = NULL;
}

void	ft_newlist(t_list **list, int fd)
{
	int		chars;
	char	*buffer;

	while (!ft_newline(list[fd]))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (NULL == buffer)
			return ;
		chars = read(fd, buffer, BUFFER_SIZE);
		if (!chars)
		{
			free(buffer);
			return ;
		}
		buffer[chars] = '\0';
		ft_append(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	ft_newlist(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = ft_getline(list);
	ft_cleanlist(&list);
	return (next_line);
}
