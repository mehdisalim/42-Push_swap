/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:23:15 by esalim            #+#    #+#             */
/*   Updated: 2023/02/14 23:54:53 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (is_empty(stack_b))
		return ;
	push(stack_a, pop(stack_b));
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	if (is_empty(stack_a))
		return ;
	push(stack_b, pop(stack_a));
	ft_putendl_fd("pb", 1);
}
