/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:22:21 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/05/31 11:13:26 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct slist	*next;
}				t_list;

char	*get_next_line(int fd);
void	ft_newlist(t_list **list, int fd);
void	ft_newlist(t_list **list, int fd);
void	ft_append(t_list **list, char *buffer);

int	ft_newline(t_list *list);
t_list	*ft_lastnode(t_list *list);

#endif