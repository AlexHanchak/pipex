/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:57:09 by ohanchak          #+#    #+#             */
/*   Updated: 2022/10/28 17:00:30 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if ((!dst && !src) || ((!dst || !src) && !n))
		return (dst);
	while (n > 0)
	{
		n--;
		*((unsigned char *)dst + n) = *((unsigned char *)src + n);
	}
	return (dst);
}
