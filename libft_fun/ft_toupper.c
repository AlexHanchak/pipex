/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:14:29 by ohanchak          #+#    #+#             */
/*   Updated: 2022/10/28 16:39:29 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	uch;

	uch = (unsigned char)c;
	if (c >= 97 && c <= 122)
	{
		uch = uch - 32;
		c = (int)uch;
	}
	return (c);
}
