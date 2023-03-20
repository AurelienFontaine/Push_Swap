# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontain <afontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 12:51:01 by afontain          #+#    #+#              #
#    Updated: 2023/03/20 15:03:41 by afontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

BONUS		=	checker

OBJS_DIR	= objs

SRCS		=	utils.c swap.c small_sort.c rotate.c reverse_rotate.c \
			 	push.c main.c lst_utils.c checker.c algo_utils.c \
 				algo_sort.c optimisation.c find_index.c

SRCS_BONUS	=	utils.c swap.c small_sort.c rotate.c reverse_rotate.c \
			 	push.c lst_utils.c checker.c algo_utils.c \
 				algo_sort.c optimisation.c find_index.c \
				BONUS/checker_bonus.c BONUS/get_next_line_utils.c \
				BONUS/get_next_line.c BONUS/main.c 

OBJS		=	${SRCS:%.c=%.o}

OBJS_BONUS	=	${SRCS_BONUS:%.c=%.o}

CC			=	clang

RM			=	rm -rf

GREEN		=	\033[1;32m

DEFAULT		=	\033[0m

CFLAGS		=	-Wall -Werror -Wextra -g3

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

$(BONUS):	${OBJS_BONUS}
		${CC} ${CFLAGS} ${OBJS_BONUS} -o ${BONUS}

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR) :
	@ mkdir -p $@
	@ mkdir -p objs/BONUS
	
all:		${NAME}

bonus:	${BONUS}

clean:		
		${RM} ${OBJS}
		${RM} ${OBJS_BONUS}

fclean:		clean
		${RM} ${NAME}
		${RM} ${BONUS}
		@echo "\n${GREEN}Everything cleaned${DEFAULT}"

re:			fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re bonus

# NAME = 	push_swap
# CHECK_NAME = checker
# CC = 	gcc
# RM =	rm -f
# CFLAGS = -Werror -Wextra -Wall -g3

# SRC = utils.c swap.c small_sort.c rotate.c reverse_rotate.c \
# 	push.c main.c lst_utils.c checker.c algo_utils.c \
# 	algo_sort.c optimisation.c find_index.c

# BONUS_SRCS = checker_bonus.c get_next_line_utils.c get_next_line.c \
# 	main_bonus.c 

# OBJS = $(SRC:.c=.o)

# BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# $(NAME): $(OBJS)
# 	${CC} ${CFLAGS} $(OBJS) -o $(NAME)

# $(BONUS): $(BONUS_OBJS)
# 		${CC} ${CFLAGS} $(BONUS_OBJS) -o ${CHECK_NAME}

# .c.o:
# 	${CC} $(CFLAGS) -c $< -o $(<:.c=.o)

# all:	$(NAME)

# clean:
# 	$(RM) $(OBJS) $(BONUS_OBJS)

# fclean: clean
# 	$(RM) $(NAME)

# re: 	fclean all

# bonus:	$(BONUS)
		
# .PHONY:	all clean fclean re bonus