/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:35:50 by ohanchak          #+#    #+#             */
/*   Updated: 2022/10/28 17:00:24 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hcount;
	size_t	ncount;
	size_t	nlen;

	hcount = 0;
	nlen = 0;
	while (needle[nlen])
		nlen++;
	if (!nlen)
		return ((char *)haystack);
	if (!len)
		return (0);
	while (haystack[hcount] && hcount + nlen <= len)
	{
		ncount = 0;
		while (haystack[hcount + ncount] == needle[ncount] && ncount < nlen)
			if (++ncount == nlen)
				return ((char *)&haystack[hcount]);
		hcount++;
	}
	return (0);
}
