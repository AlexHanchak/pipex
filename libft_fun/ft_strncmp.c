/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:20:57 by ohanchak          #+#    #+#             */
/*   Updated: 2023/02/15 17:25:14 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int				i;
	unsigned char	*temps1;
	unsigned char	*temps2;

	i = 0;
	temps1 = (unsigned char *) str1;
	temps2 = (unsigned char *) str2;
	while ((size_t)i < n)
	{
		if (temps1[i] != temps2[i])
		{
			if (temps1[i] == '\0')
				return (-1);
			if (temps2[i] == '\0')
				return (1);
			return (temps1[i] - temps2[i]);
		}
		if (temps1[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
