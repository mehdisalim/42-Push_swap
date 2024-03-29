/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:22:48 by esalim            #+#    #+#             */
/*   Updated: 2023/02/15 15:40:08 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_s(t_stack *stack)
{
	int	tmp;
	int	tmp2;

	if (is_empty(stack) || stack->capacity < 2)
		return ;
	tmp = pop(stack);
	tmp2 = pop(stack);
	push(stack, tmp);
	push(stack, tmp2);
}

void	sa(t_stack *stack_a, int show)
{
	ft_s(stack_a);
	if (show)
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack *stack_b, int show)
{
	ft_s(stack_b);
	if (show)
		ft_putendl_fd("sb", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int show)
{
	ft_s(stack_a);
	ft_s(stack_b);
	if (show)
		ft_putendl_fd("ss", 1);
}
