# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esalim <esalim@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 22:29:48 by esalim            #+#    #+#              #
#    Updated: 2023/01/22 13:41:48 by esalim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	main.c
OBJS	=	$(SRCS:.c=.o)

RM		=	rm -rf
MAKE	=	make -C

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(MAKE) libft
	$(MAKE) ft_printf
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a ft_printf/libftprintf.a -o $(NAME)

%.o 	:	%.c
	@$(CC) $(CFLAGS) -c $^

clean	:
	$(MAKE) libft/ clean
	$(MAKE) ft_printf/ clean
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all
