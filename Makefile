# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 12:37:45 by ohanchak          #+#    #+#              #
#    Updated: 2023/01/28 12:54:42 by ohanchak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
CC		=	cc
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf


SRC		=	pipex.h	pipex_bonus.h
Mproj	=	pipex.c	free.c	proces.c
obj_src	=	$(Mproj SRC:.c=.o)

# SRC_BONUS	= 
# Bproj		=
# bobj_src	=

# LibFt func
# libft_func	=
# f_obj			=


# collect
%.o: %.c $(SRC)	Makefile
							@${CC} ${FLAGS} -c $< -o $@

$(NAME):					$(f_obj) $(obj_src)
								@$(CC) $(f_obj) $(obj_src) -o $(NAME)


all:						$(NAME)

clean:
							@$(RM) $(obj_src)
							@$(RM) $(bobj_src)
							@$(RM) $(f_obj)

fclean:	clean
							@$(RM) $(NAME)

re:							fclean all

.PHONY:						all clean fclean re