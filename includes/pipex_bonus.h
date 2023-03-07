/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:12:01 by ohanchak          #+#    #+#             */
/*   Updated: 2023/03/06 15:28:47 by ohanchak         ###   ########.fr       */
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

typedef struct s_pipb
{
    int     infile;
    int     outfile;
	char    *envpath;
	char	**cmdpaths;
	char	*cmd;
	char	**cmd_args;
	pid_t	pid;
	int     cmd_numbs;
	int     pipe_numbs;
	char	*pipe;
	int     index;
}t_pipb;






#endif