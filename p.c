/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:45:49 by ohanchak          #+#    #+#             */
/*   Updated: 2023/01/28 12:34:36 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "pipex.h"

char	*path_to_bins(char **env)
{
	char	*path;
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		path = env[i];
		printf("%s\n", path);
		if (ft_strncmp("PATH", path, 4) == 0)
			break ;
		i++;
	}
	if (access(path, F_OK) < 0)
		return (NULL);
}

int	main(int argc, char *argv[])
{
	char	*a = "ping";
	char	*envp[] = a;

	printf("%s\n", path_to_bins(envp));
// 	int	fd[2];
// 	int	pid1;
// 	int	pid2;
// 	t_pipex	pipex;

// 	if (pipe(fd) == -1)
// 		return (1);

// // read 1 file
// 	pipex.infile = open(argv[1], O_RDONLY);
// 	pipex.outfile = (argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR);
// 	pid1 = fork();
// 	if (pid1 < 0)
// 		return (2);
// 	pid2 = fork();
// 	if (pid2 < 0)
// 		return (2);
// /*child*/
// 	if (pid1 == 0)
// 		execlp("ping", "ping", "-c", "5", "google.com", NULL);
// 	if (pid2 == 0)
// 	{
// 		execlp("grep", "grep", "round-trip");
// 	}
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);

	return (0);
}
