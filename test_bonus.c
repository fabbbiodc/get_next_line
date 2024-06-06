/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:35:10 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/06/06 12:05:19 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int main(int argc, char **argv)
{
	int i;
	int fd[argc];
	char *line[argc];
	i = 0;

	while (i < argc)
	{
		fd[i] = open(argv[i], O_RDONLY);
		if (fd[i] < 0)
			perror("Check your FDs");
		i++;
	}
	i = 0;
	while (i < argc)
	{
		line[i] = get_next_line(fd[i]);
		while (line[i])
		{
			if (line[i])
			{
				printf("%s", line[i]);
				free(line[i]);
			}
			printf("\n");
		}
		i++;
	}
	return (0);
}