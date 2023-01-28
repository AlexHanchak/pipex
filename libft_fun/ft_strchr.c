/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:15:09 by ohanchak          #+#    #+#             */
/*   Updated: 2022/11/01 15:21:30 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *arrch, int c)
{
	char	*str;
	int		i;

	str = (char *) arrch;
	i = 0;
	if ((char)c == '\0')
	{
		i = ft_strlen(str);
		return (&str[i]);
	}
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
