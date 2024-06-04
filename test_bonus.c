/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:35:10 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/06/04 19:22:13 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int main(int argc, char **argv)
{
	int i;
	int fd[argc];

	i = 0;

	while (i < argc)
	{
		fd[i++] = open(argv[i], O_RDONLY);
		if (fd[i] < 0)
			perror("Check your FDs");
	}
	i = 0;
	


		
		
		
		
		
		
		
		if (fd == -1)
		{
			perror("Error opening file");
			return 1;
		}

		char *line;
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("%s", line);
			free(line);
		}
	close(fd);
	}
    return 0;

}