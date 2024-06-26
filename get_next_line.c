/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:22:05 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/06/04 15:55:27 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	while (!ft_newline(*list))
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
		ft_append(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*nextline;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ft_newlist(&list, fd);
	if (list == NULL)
		return (NULL);
	nextline = ft_getline(list);
	ft_cleanlist(&list);
	return (nextline);
}
