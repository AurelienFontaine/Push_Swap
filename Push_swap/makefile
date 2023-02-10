# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontain <afontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 12:51:01 by afontain          #+#    #+#              #
#    Updated: 2023/02/03 18:28:42 by afontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	push_swap
CC = 	gcc
RM =	rm -f
CFLAGS = -Werror -Wextra -Wall -g3

SRC = 

BONUS =	
	

BONUS_OBJS = $(BONUS:.c=.o)

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	${CC} ${CFLAGS} $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: 	fclean all

# bonus:	$(BONUS_OBJS)
# 		 $(NAME) $(BONUS_OBJS)
		
.PHONY:	all clean fclean re bonus