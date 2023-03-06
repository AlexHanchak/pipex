/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:11:25 by ohanchak          #+#    #+#             */
/*   Updated: 2023/03/06 15:46:34 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	close_ppipe(t_pipex *pipex)
{
	close(pipex->tube[0]);
}

int main(int argc, char *argv[], char *envp[])
{
	t_pipex pipex;
	
	return (0);
}