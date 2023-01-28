/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:04:45 by ohanchak          #+#    #+#             */
/*   Updated: 2022/10/27 16:14:21 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dist, const char *src, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (i < len && dist[i] != '\0')
		i++;
	if (i == len)
		return (i + ft_strlen(src));
	k = i;
	while (src[j] != 0)
	{
		if (i < len - 1)
		{
			dist[k] = src[j];
			k++;
		}
		i++;
		j++;
	}
	dist[k] = '\0';
	return (i);
}
