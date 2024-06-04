/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:19:08 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/06/04 16:30:15 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_cleanlist(t_list **list)
{
	t_list	*lastnode;
	t_list	*cleannode;
	int		i;
	int		k;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	cleannode = malloc(sizeof(t_list));
	if (NULL == buffer || NULL == cleannode)
		return ;
	lastnode = ft_lastnode(*list);
	i = 0;
	k = 0;
	while (lastnode->content[i] && lastnode->content[i] != '\n')
		i++;
	while (lastnode->content[i] && lastnode->content[i++])
		buffer[k++] = lastnode->content[i];
	buffer[k] = '\0';
	cleannode->content = buffer;
	cleannode->next = NULL;
	ft_freelist(list, cleannode, buffer);
}

char	*ft_getline(t_list *list)
{
	int		len;
	char	*line;

	if (NULL == list)
		return (NULL);
	len = ft_linelength(list);
	line = malloc(len + 1);
	if (NULL == line)
		return (NULL);
	ft_copyline(list, line);
	return (line);
}

void	ft_append(t_list **list, char *buffer, int fd)
{
	t_list	*newnode;
	t_list	*lastnode;

	lastnode = ft_lastnode(list[fd]);
	newnode = malloc(sizeof(t_list));
	if (NULL == newnode)
		return ;
	if (NULL == lastnode)
		list[fd] = newnode;
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
		if (!chars || chars <= -1)
		{
			free(buffer);
			return ;
		}
		buffer[chars] = '\0';
		ft_append(list, buffer, fd);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list[4096];
	char			*nextline;

	if (fd < 0 || fd >= 4096 || BUFFER_SIZE < 1)
		return (NULL);
	ft_newlist(list, fd);
	if (list[fd] == NULL)
		return (NULL);
	nextline = ft_getline(list[fd]);
	ft_cleanlist(&list[fd]);
	return (nextline);
}
