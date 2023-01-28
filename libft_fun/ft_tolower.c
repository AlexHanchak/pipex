/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:14:48 by ohanchak          #+#    #+#             */
/*   Updated: 2022/10/18 14:49:31 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	uch;

	uch = (unsigned char)c;
	if (c >= 65 && c <= 90)
	{
		uch = uch + 32;
		c = (int)uch;
	}
	return (c);
}
