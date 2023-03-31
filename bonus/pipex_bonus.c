/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:11:25 by ohanchak          #+#    #+#             */
/*   Updated: 2023/03/30 11:52:55 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void create_process(t_pipb *pipex)
{
	int i;

	i = 0;
	while (i <= pipex->cmd_numbs)
	{
		if (pipe(pipex->pipe + 2 * i) < 0)
			main_free(pipex);
		i++;
	}
}

void main_free(t_pipb *pipex)
{
	int i;

	i = 0;

	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd[i]);
		i++;
	}
	free(pipex->cmd);
}

void	close_ppipe(t_pipb *pipex)
{
	int i;

	i = 0;
	while (pipex->pipe_numbs)
	{
		close(pipex->pipe[i]);
		i++;
	}
}

void infile(char **argv, t_pipb *pipex)
{
	if (!ft_strncmp("here_doc", argv[1], 9))
		here_doc(argv[2], pipex);
	else
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile < 0)
			return 1;
	}

}

void outfile(char *argv, t_pipb *pipex)
{
	if (pipex->here_doc)
		pipex->outfile = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0000644);
	else
		pipex->outfile = open(argv, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (pipex->outfile < 0)
		return 1;
}

int main(int argc, char *argv[], char *envp[])
{
	t_pipb pipex;

	if (argc < args_in(argv[1], &pipex))
		return 1;
//		return ("errror")????????????


	return (0);
}