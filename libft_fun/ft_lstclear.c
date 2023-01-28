/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:13:41 by ohanchak          #+#    #+#             */
/*   Updated: 2022/10/30 16:38:29 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*n;

	if (lst && del)
	{
		temp = *lst;
		if (temp)
		{
			del(temp->content);
			while (temp->next)
			{
				n = temp->next;
				free(temp);
				temp = n;
				del(temp->content);
			}
			free(temp);
		}
		*lst = 0;
	}
}
