/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:11:25 by ohanchak          #+#    #+#             */
/*   Updated: 2023/03/16 11:47:08 by ohanchak         ###   ########.fr       */
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

void	close_ppipe(t_pipb *pipex)
{
	int i;

	i = 0;
	while (pipb->pipe_numbs)
	{
		close(pipb->pipe[i]);
		i++;
	}
}

void infile(char **argv, t_pipb *pipex)
{
	
}

int main(int argc, char *argv[], char *envp[])
{
	t_pipb pipex;

	if (argc < args_in(argv[1], &pipex))
//		return ("errror")????????????

	return (0);
}