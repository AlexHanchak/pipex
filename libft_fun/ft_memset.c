/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:41:53 by ohanchak          #+#    #+#             */
/*   Updated: 2022/10/24 19:12:54 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_memset(void *str, int c, size_t len)
{	
	unsigned char	*p;

	p = str;
	while (len > 0)
	{
		*p = c;
		p++;
		len--;
	}
	return (str);
}
