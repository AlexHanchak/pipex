/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:39:19 by ohanchak          #+#    #+#             */
/*   Updated: 2023/01/27 17:09:26 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
# include "../libft_fun/libft.h"
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

void	first_process(t_pipex pipex, char *argv[], char *envp[]);
void	second_process(t_pipex pipex, char *argv[], char *envp[]);

void	main_free(t_pipex *pipex);
void	proc_free(t_pipex *pipex);

size_t   ft_strlen(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif