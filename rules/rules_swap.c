/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:22:48 by esalim            #+#    #+#             */
/*   Updated: 2023/02/14 19:24:20 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ft_s(t_stack *stack)
{
    if (isEmpty(stack) || stack->capacity < 2)
        return ;
    int tmp, tmp2;
    tmp = pop(stack);
    tmp2 = pop(stack);
    push(stack, tmp);
    push(stack, tmp2);
}

void    sa(t_stack *stack_a)
{
    ft_s(stack_a);
    ft_printf("sa\n");
}

void    sb(t_stack *stack_b)
{
    ft_s(stack_b);
    ft_printf("sb\n");
}

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    ft_s(stack_a);
    ft_s(stack_b);
    ft_printf("ss\n");
}
