/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:22:21 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/05/31 18:11:23 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

// main function

char	*get_next_line(int fd);
void	ft_newlist(t_list **list, int fd);
void	ft_append(t_list **list, char *buffer);
char	*ft_getline(t_list *list);
void	ft_cleanlist(t_list **list);

// utils

int		ft_newline(t_list *list);
t_list	*ft_lastnode(t_list *list);
int		ft_linelength(t_list *list);
void	ft_copyline(t_list *list, char *str);
void	ft_freelist(t_list **list, t_list *cleannode, char *buffer);

#endif