# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 13:11:36 by jdurand           #+#    #+#              #
#    Updated: 2019/10/21 16:39:47 by jdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(wildcard *.c)

RM		=	rm -f

all		:
			gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 $(SRCS)

clean	:
			$(RM) $(wildcard *.o)

fclean	:	clean
			$(RM) $(wildcard *.out)

re		:	fclean all

sani	:
			gcc -Wall -Wextra -Werror  \
			-g3 -fsanitize=address -D BUFFER_SIZE=5000000 $(SRCS)

exe		:
			./a.out

re sani :	fclean sani

.PHONY	:	clean fclean all re sani
