/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:35:45 by ohanchak          #+#    #+#             */
/*   Updated: 2022/10/19 14:49:28 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int	cur;

	if (size == 0)
		return (ft_strlen(src));
	cur = 0;
	while (src[cur] != 0 && cur < (size - 1))
	{
		dest[cur] = src[cur];
		cur++;
	}
	dest[cur] = 0;
	return (ft_strlen(src));
}
