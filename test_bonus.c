/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-cecc <fdi-cecc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:35:10 by fdi-cecc          #+#    #+#             */
/*   Updated: 2024/06/06 17:03:53 by fdi-cecc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int main(int argc, char **argv)
{
    int i;
    int *fd;
    char **lines;
    int *file_done;
    int files_remaining;

    if (argc < 2)
    {
        printf("Specify the files please: %s file1 file2 ...\n", argv[0]);
        return 1;
    }

    // Allocate memory for file descriptors, lines, and file status
    fd = (int *)malloc((argc - 1) * sizeof(int));
    lines = (char **)malloc((argc - 1) * sizeof(char *));
    file_done = (int *)malloc((argc - 1) * sizeof(int));

    for (i = 0; i < argc - 1; i++)
    {
        fd[i] = open(argv[i + 1], O_RDONLY);
        if (fd[i] < 0)
        {
            perror("Error opening file");
            free(fd);
            free(lines);
            free(file_done);
            return 1;
        }
        lines[i] = NULL;
        file_done[i] = 0; // Initialize file status as not done
    }

    files_remaining = argc - 1;
    while (files_remaining > 0)
    {
        for (i = 0; i < argc - 1; i++)
        {
            if (!file_done[i])
            {
                if (lines[i] != NULL)
                {
                    free(lines[i]);
                }
                lines[i] = get_next_line(fd[i]);
                if (lines[i] != NULL)
                {
                    printf("%s", lines[i]);
                }
                else
                {
                    file_done[i] = 1; // Mark this file as done
                    files_remaining--;
                }
            }
        }
    }

    for (i = 0; i < argc - 1; i++)
    {
        close(fd[i]);
        if (lines[i] != NULL)
        {
            free(lines[i]);
        }
    }

    free(fd);
    free(lines);
    free(file_done);

    return 0;
}


/* int main(int argc, char **argv)
{
	int i;
	int fd[argc - 1];
	char *line;
	i = 1;

	   if (argc < 2)
    {
        printf("Specify the files please: %s file1 file2 ...\n", argv[0]);
        return (1);
    }

	while (i < argc)
	{
		fd[i - 1] = open(argv[i], O_RDONLY);
		if (fd[i - 1] < 0)
		{
			perror("Check your FDs");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		while ((line = get_next_line(fd[i])) != NULL)
		{
			if (line[i])
			{
				printf("%s", line);
				free(line);
			}
			printf("\n");
		}
		close(fd[i]);
		i++;
	}
	return (0);
}  */

//cc -Wall -Werror -Wextra test_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c -o test_bonus