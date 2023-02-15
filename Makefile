# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esalim <esalim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 22:29:48 by esalim            #+#    #+#              #
#    Updated: 2023/02/15 20:47:37 by esalim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RULES_DIR	= rules
ALGO_DIR	= algos
UTILS_DIR	= utils
INCLUDES	= includes

NAME		=	push_swap
BONUS		=	checker

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
SRCS		=	${RULES_DIR}/rules_push.c \
				${RULES_DIR}/rules_rotate.c \
				${RULES_DIR}/rules_rotate_extra.c \
				${RULES_DIR}/rules_swap.c \
				${ALGO_DIR}/apply_rules.c \
				${ALGO_DIR}/best_move.c \
				${ALGO_DIR}/chunk_algo.c \
				${UTILS_DIR}/utils_checking_args.c \
				${UTILS_DIR}/utils_push_swap.c \
				${UTILS_DIR}/utils_sort.c \
				sort.c stack.c destroy_program.c

SRCSMAND	=	$(SRCS) push_swap.c

SRCSBONUS	=	$(SRCS) checker.c

OBJSMAND	=	$(SRCSMAND:.c=.o)
OBJSBONUS	=	$(SRCSBONUS:.c=.o)

RM			=	rm -rf
MAKE		=	make -C

all			:	$(NAME)

$(NAME)		:	$(OBJSMAND)
	$(MAKE) libft
	$(CC) $(CFLAGS) $(OBJSMAND) libft/libft.a -o $(NAME)

%.o 		:	%.c
	@$(CC) $(CFLAGS) -c -I$(INCLUDES) $^ -o $@

bonus		:	$(OBJSBONUS)
	$(MAKE) libft
	$(CC) $(CFLAGS) $(OBJSBONUS) libft/libft.a -o $(BONUS)

clean		:
	$(MAKE) libft/ clean
	$(RM) $(OBJSMAND) $(OBJSBONUS)

fclean		:	clean
	$(MAKE) libft/ fclean
	$(RM) $(NAME) $(BONUS)

re			:	fclean all
