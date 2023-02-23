/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:45:49 by ohanchak          #+#    #+#             */
/*   Updated: 2023/02/23 14:49:44 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*path_to_bins(char **env)
{
    char	*path;
    int		i;

    i = 0;
    while (env[i] != NULL)
    {
        path = env[i];
        // printf("%s\n", path);
        if (ft_strncmp("PATH", path, 4) == 0)
            break ;
        i++;
    }
//    if (access(path, F_OK) < 0)
    return (NULL);
}

void    close_pipe(t_pipex *pipex)
{
    close(pipex->tube[0]);
    close(pipex->tube[1]);
}

int	main(int argc, char *argv[], char *envp[])
{
    t_pipex pipex;

    if (argc != 5)
        return (1);
    pipex.infile = open(argv[1], O_RDONLY);
    if (pipex.infile <0)
        return (1);
    pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
    if (pipex.outfile <0)
        return (1);
    if (pipe(pipex.tube) < 0)
        return (1);
    pipex.paths = path_to_bins(envp);
    pipex.cmd_paths = ft_split(pipex.paths, ':');
    pipex.pid1 = fork();
    if (pipex.pid1 == 0)
        first_process(pipex, argv, envp);
    pipex.pid2 = fork();
    if (pipex.pid2 == 0)
        second_process(pipex, argv, envp);
    close_pipe(&pipex);
    waitpid(pipex.pid1, NULL, 0);
    waitpid(pipex.pid2, NULL, 0);
    main_free(&pipex);
    return (0);
}
