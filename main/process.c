/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:15:52 by ohanchak          #+#    #+#             */
/*   Updated: 2023/03/22 13:37:41 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	proc_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}

void	main_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
}

void	first_process(t_pipex pipex, char *argv[], char *envp[])
{
	
	if (pipex.infile < 0) 
	{
		if (access(argv[1], F_OK) != -1)
			write(2, "permission denied\n", 18);
		else
			write(2, "no such file or directory\n", 26);
		exit(1);
	}
	dup2(pipex.tube[1], 1);
	close(pipex.tube[0]);
	dup2(pipex.infile, 0);
	close(pipex.infile);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	
	if (!pipex.cmd)
	{
		proc_free(&pipex);
		perror("Command not found!");
		exit(1);
	}
	if (execve(pipex.cmd, pipex.cmd_args, envp) == -1)
	{
		write(2, "Command not found!\n", 19);
		exit(1);
	}
}

void	second_process(t_pipex pipex, char *argv[], char *envp[])
{
	
	if (pipex.outfile < 0) 
	{
		write(2, "permission denied\n", 18);
		exit(1);
	}
	dup2(pipex.tube[0], 0);
	close(pipex.tube[1]);
	dup2(pipex.outfile, 1);
	close(pipex.outfile);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		proc_free(&pipex);
		perror("Command not found!");
		exit(1);
	}
	if (execve(pipex.cmd, pipex.cmd_args, envp) == -1)
	{
		write(2, "Command not found!\n", 19);
		exit(1);
	}
}
