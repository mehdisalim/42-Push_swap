/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:27:44 by esalim            #+#    #+#             */
/*   Updated: 2023/01/28 23:07:14 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void    setup_stack(t_stack **stack_a, t_stack **stack_b, char **numbers, int capacity)
{
    int i = -1;
    *stack_a = oncreate(capacity);
    *stack_b = oncreate(capacity);
    clear(*stack_a);
    clear(*stack_b);
    i = -1;
    while (++i < capacity)
    {
        if (!check_isdigits(numbers[i]))
        {
            ft_putstr_fd("Error: the argement should be a digits\n", 2);
            exit(1);
        }
        push(*stack_a, ft_atoi(numbers[i]));
    }
}

void    print_stack(t_stack *stack)
{
    int *arr = stack->stack;
    int i = stack->top;
    while (i > -1)
        ft_printf("%d\n", arr[i--]);
}

int main(int ac, char **av)
{
    char    *args = get_all_args(ac, av);
    char    **numbers = ft_split(args, ' ');
    int capacity = get_num_count(numbers); 
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    setup_stack(&stack_a, &stack_b, numbers, capacity);
    detect_sort(stack_a, stack_b);
    print_stack(stack_a);
    return (0);
}
