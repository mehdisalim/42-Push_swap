/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:24:44 by esalim            #+#    #+#             */
/*   Updated: 2023/02/14 23:34:09 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *stack_a)
{
	ft_r(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack *stack_b)
{
	ft_r(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rra(t_stack *stack_a)
{
	ft_rr(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *stack_b)
{
	ft_rr(stack_b);
	ft_putendl_fd("rrb", 1);
}
