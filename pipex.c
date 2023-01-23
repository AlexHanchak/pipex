<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:45:49 by ohanchak          #+#    #+#             */
/*   Updated: 2023/01/23 12:08:06 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys.wait.h>

int main(int argc, char *argv[])
{
    int fd[2];
    if (pipe(fd) == -1)
        return (1);

    int pid1 = fork();
    if (pid1 < 0)
        return (2);
//child
    if (pid1 == 0)
        execlp("ping", "-c", "5", "google.com", NULL);

    waitpid(pid1, NULL, 0);

    return (0);
}