/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:15:31 by ohanchak          #+#    #+#             */
/*   Updated: 2022/10/21 18:56:37 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *src, int c)
{
	char	*str;
	char	chr;
	int		i;

	str = (char *)src;
	chr = (char) c;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == chr)
			return (&str[i]);
		i--;
	}
	return (0);
}
