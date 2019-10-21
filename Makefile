# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 13:11:36 by jdurand           #+#    #+#              #
#    Updated: 2019/10/21 15:19:37 by jdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(wildcard *.c)

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

all		:	$(OBJS)
			gcc -Wall -Wextra -Werror $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:
			$(RM) $(OBJS) $(wildcard *.out)

re		:	fclean all

re sani :	fclean sani

sani	:	$(OBJS)
			gcc -Wall -Wextra -Werror  \
			-g3 -fsanitize=address -D BUFFER_SIZE=500 $(OBJS)

.PHONY	:	clean fclean all re sani
