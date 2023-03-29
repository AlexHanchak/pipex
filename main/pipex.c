/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:45:49 by ohanchak          #+#    #+#             */
/*   Updated: 2023/03/22 13:48:51 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*path_to_bins(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

void	close_pipe(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	int status;

	if (argc != 5)
		{
		write(2, "Invalid number of arguments.\n", 29);
		return(1);
		}
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipe(pipex.tube) < 0)
	{
		write(2, "nothing in tube.\n", 18);
		return (127);
	}
	pipex.paths = path_to_bins(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
			first_process(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_process(pipex, argv, envp);
	close_pipe(&pipex);

	waitpid(pipex.pid2, &status, 0);
	waitpid(pipex.pid1, NULL, 0);
	main_free(&pipex);
	if (WIFEXITED(status))
		return(WEXITSTATUS(status));
	return (0);
}
