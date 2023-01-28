/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:24:46 by ohanchak          #+#    #+#             */
/*   Updated: 2023/01/03 13:54:04 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char			*ptr;
	unsigned int	i;
	size_t			x;

	i = 0;
	x = nelem * elsize;
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
	ft_free(&*next_line);
	*next_line = tmp;
	return (*next_line);
}

char	*ft_output(char **next_line, int position, int bytes)
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
		ft_free(&*next_line);
	else
		*next_line = ft_update_nl(&*next_line, position);
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
	static char	*next_line[10240];
	char		*buff;
	int			position;
	int			bytes;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 10240)
		return (NULL);
	buff = NULL;
	position = ft_strchr(next_line[fd], '\n', 0);
	while (position == -1 && position != -5)
	{
		buff = ft_calloc(BUFFER_SIZE + 1, 1);
		if (buff == NULL)
			return (NULL);
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (free_buff(buff, &next_line[fd], bytes))
			return (NULL);
		next_line[fd] = ft_strnjoin(next_line[fd], buff, bytes);
		position = ft_strchr(next_line[fd], '\n', 1);
		ft_free(&buff);
	}
	ft_free(&buff);
	return (ft_output(&next_line[fd], position, bytes));
}
