/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:51:37 by ohanchak          #+#    #+#             */
/*   Updated: 2023/02/15 17:28:04 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

void	ft_free(char **p);
size_t	ft_strlen(const char *s);
int		ft_strchr(char *s, int c, int flag);
char	*ft_strnjoin(char *s1, char *s2, int n);
char	*ft_strndup(char *str, int n);
void	*ft_calloc(size_t nelem, size_t elsize);
char	*ft_update_nl(char **next_line, int position);
char	*ft_output(char **next_line, int position, int bytes);
char	*get_next_line(int fd);

#endif
