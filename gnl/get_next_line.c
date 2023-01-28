/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:51:26 by ohanchak          #+#    #+#             */
/*   Updated: 2023/01/03 13:52:14 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*ptr;
	unsigned int	i;
	size_t			x;

	i = 0;
	x = count * size;
	ptr = (char *)malloc(x);
	if (ptr == NULL)
		return (0);
	while (i < x)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_update_nl(char **next_line, int position)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*next_line) - position;
	tmp = ft_strndup(*next_line + position, len);
	ft_free(next_line);
	*next_line = tmp;
	return (*next_line);
}

char	*ft_out(char **next_line, int position, int bytes)
{
	char	*line;

	if (((bytes == 0 || bytes == -1) && !*next_line))
	{
		if (*next_line)
			return (*next_line);
		return (NULL);
	}
	line = NULL;
	if (position == -1)
		position = ft_strlen(*next_line);
	else
		position++;
	line = ft_strndup(*next_line, position);
	if (position == ft_strlen(*next_line))
		ft_free(next_line);
	else
		*next_line = ft_update_nl(next_line, position);
	return (line);
}

char	free_buff(char *buff, char **next_line, int bytes)
{
	if (bytes == -1)
	{
		ft_free(&buff);
		ft_free(next_line);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*buff;
	int			position;
	int			bytes;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	buff = NULL;
	position = ft_strchr(next_line, '\n', 0);
	while (position == -1)
	{
		buff = ft_calloc(BUFFER_SIZE + 1, 1);
		if (buff == NULL)
			return (NULL);
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (free_buff(buff, &next_line, bytes))
			return (NULL);
		next_line = ft_strnjoin(next_line, buff, bytes);
		position = ft_strchr(next_line, '\n', 1);
		ft_free(&buff);
	}
	ft_free(&buff);
	return (ft_out(&next_line, position, bytes));
}
