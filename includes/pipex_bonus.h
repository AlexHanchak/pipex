/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:12:01 by ohanchak          #+#    #+#             */
/*   Updated: 2023/03/16 12:11:35 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
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

typedef struct s_pipb
{
    int     infile;
    int     outfile;
	char    *envpath;
	char	**cmdpaths;
	char	*cmd;
	char	**cmd_args;
	int		here_doc;
	pid_t	pid;
	int     cmd_numbs;
	int     pipe_numbs;
	char	*pipe;
	int     index;
}t_pipb;

void infile(char **argv, t_pipb *pipex);

void outfile(char *argv, t_pipb *pipex);

void main_free(t_pipb *pipex);

void	close_ppipe(t_pipb *pipex);


char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif