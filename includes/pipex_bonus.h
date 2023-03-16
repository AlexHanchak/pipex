/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:12:01 by ohanchak          #+#    #+#             */
/*   Updated: 2023/03/07 13:29:48 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>
/* open, unlink */
# include <fcntl.h>
/* waitpid, wait */
# include <sys/wait.h>
/* strerror */
# include <string.h>
/*to perror*/
# include <stdio.h>
# include "../gnl/get_next_line.h"
# include "../includes/pipex.h"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;






#endif