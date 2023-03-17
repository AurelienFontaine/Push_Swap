# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontain <afontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 12:51:01 by afontain          #+#    #+#              #
#    Updated: 2023/03/17 18:52:11 by afontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	push_swap
CHECK_NAME = checker
CC = 	gcc
RM =	rm -f
CFLAGS = -Werror -Wextra -Wall -g3

SRC = utils.c swap.c small_sort.c rotate.c reverse_rotate.c \
	push.c main.c lst_utils.c checker.c algo_utils.c \
	algo_sort.c optimisation.c find_index.c\

BONUS = checker_bonus.c get_next_line_utils.c get_next_line.c \
	main_bonus.c \

OBJS = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

$(NAME): $(OBJS)
	${CC} ${CFLAGS} $(OBJS) -o $(NAME)

.c.o:
	${CC} $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: 	fclean all

bonus:	$(BONUS_OBJS)
		${CC} ${CFLAGS} $(BONUS_OBJS) -o ${CHECK_NAME}
		
.PHONY:	all clean fclean re bonus