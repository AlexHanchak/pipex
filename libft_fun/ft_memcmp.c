/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:21:30 by ohanchak          #+#    #+#             */
/*   Updated: 2022/11/01 15:20:22 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const char *str1, char *str2, size_t n)
{
	unsigned char	*pstr1;
	unsigned char	*pstr2;

	pstr1 = (unsigned char *)str1;
	pstr2 = (unsigned char *)str2;
	while (n > 0)
	{
		if (*pstr1 != *pstr2)
			return (*pstr1 - *pstr2);
		pstr1++;
		pstr2++;
		n--;
	}
	return (0);
}
