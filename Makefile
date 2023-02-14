# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esalim <esalim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 22:29:48 by esalim            #+#    #+#              #
#    Updated: 2023/02/14 16:22:48 by esalim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	rules.c stack.c push_swap_utils.c push_swap.c sort.c main.c best_move.c chunk_algo.c free_leaks.c
OBJS	=	$(SRCS:.c=.o)

RM		=	rm -rf
MAKE	=	make -C

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(MAKE) libft
	$(MAKE) ft_printf
	$(CC) $(CFLAGS) -g $(OBJS) libft/libft.a ft_printf/libftprintf.a -o $(NAME)

%.o 	:	%.c
	@$(CC) $(CFLAGS) -c $^

clean	:
	$(MAKE) libft/ clean
	$(MAKE) ft_printf/ clean
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all
