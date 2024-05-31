/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:22:14 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/05/31 15:25:51 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_copyline(t_list *list, char *str)
{
	int	i;
	int	k;

	if (NULL == list)
		return;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->content[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
}

int	ft_linelength(t_list *list)
{
	int	i;
	int	len;

	if (NULL == list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

t_list	*ft_lastnode(t_list *list)
{
	if (NULL == list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	ft_newline(t_list *list)
{
	int	i;

	if (NULL == list)
		return (0);
	while (list)
	{
		while (list->content[i] && i < BUFFER_SIZE)
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
	}
	list = list->next;
}
