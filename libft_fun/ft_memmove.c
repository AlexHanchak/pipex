/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:13:46 by ohanchak          #+#    #+#             */
/*   Updated: 2022/10/27 15:14:15 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*s1;
	const char	*s2;

	i = 0;
	s1 = (char *)dst;
	s2 = (const char *)src;
	if (dst < src)
	{
		while (i < len)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len > 0)
		{
			len--;
			s1[len] = s2[len];
		}
	}
	return (s1);
}
