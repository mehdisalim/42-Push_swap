# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esalim <esalim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 22:29:48 by esalim            #+#    #+#              #
#    Updated: 2023/02/15 19:48:48 by esalim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RULES_DIR	= rules
ALGO_DIR	= algos
UTILS_DIR	= utils

NAME		=	push_swap
BONUS		=	checker

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
SRCS		=	${RULES_DIR}/rules_push.c \
				${RULES_DIR}/rules_rotate.c \
				${RULES_DIR}/rules_rotate_extra.c \
				${RULES_DIR}/rules_swap.c \
				${ALGO_DIR}/best_move.c \
				${ALGO_DIR}/chunk_algo.c \
				${ALGO_DIR}/apply_rules.c \
				${UTILS_DIR}/utils_sort.c \
				${UTILS_DIR}/utils_checking_args.c \
				${UTILS_DIR}/utils_push_swap.c \
				stack.c push_swap.c sort.c destroy_program.c

SRCSBONUS	=	${RULES_DIR}/rules_push.c \
				${RULES_DIR}/rules_rotate.c \
				${RULES_DIR}/rules_rotate_extra.c \
				${RULES_DIR}/rules_swap.c \
				${ALGO_DIR}/best_move.c \
				${ALGO_DIR}/chunk_algo.c \
				${ALGO_DIR}/apply_rules.c \
				${UTILS_DIR}/utils_sort.c \
				${UTILS_DIR}/utils_checking_args.c \
				${UTILS_DIR}/utils_push_swap.c \
				stack.c checker.c sort.c destroy_program.c

OBJS		=	$(SRCS:.c=.o)
OBJSBONUS	=	$(SRCSBONUS:.c=.o)

RM			=	rm -rf
MAKE		=	make -C

all			:	$(NAME)

$(NAME)		:	$(OBJS)
	$(MAKE) libft
	$(CC) $(CFLAGS) -g $(OBJS) libft/libft.a -o $(NAME)

%.o 		:	%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

bonus		:	$(OBJSBONUS)
	$(MAKE) libft
	$(CC) $(CFLAGS) -g $(OBJSBONUS) libft/libft.a -o $(BONUS)

clean		:
	$(MAKE) libft/ clean
	$(RM) $(OBJS) $(OBJSBONUS)

fclean		:	clean
	$(MAKE) libft/ fclean
	$(RM) $(NAME) $(BONUS)

re			:	fclean all
