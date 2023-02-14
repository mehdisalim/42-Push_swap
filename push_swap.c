/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:27:44 by esalim            #+#    #+#             */
/*   Updated: 2023/02/14 19:38:26 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setup_stack(t_stack **s_a, t_stack **s_b, char **num, int cp)
{
	int		i;
	int		check;
	long	number;

	*s_a = oncreate(cp);
	*s_b = oncreate(cp);
	i = cp;
	while (--i > -1)
	{
		check = check_isdigits(num[i]);
		number = ft_atoi(num[i]);
		if ((number > 2147483647 || number < -2147483648) || !check)
		{
			free_stack(*s_a, *s_b);
			ft_putendl_fd("Error", 2);
			exit(1);
		}
		push(*s_a, number);
	}
}

void    detect_sort(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->capacity == 2)
        sort_two(stack_a);
    else if (stack_a->capacity == 3)
        sort_three(stack_a);
     else if (stack_a->capacity == 4)
        sort_four(stack_a, stack_b);
     else if (stack_a->capacity == 5)
        sort_five(stack_a, stack_b);
    else if (stack_a->capacity > 5)
		sort_all(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	char	*args;
	char	**numbers;
	int		capacity;
	t_stack	*stack_a;
	t_stack	*stack_b;

	args = get_all_args(ac, av);
	numbers = ft_split(args, ' ');
	free(args);
	capacity = get_num_count(numbers);
	stack_a = NULL;
	stack_b = NULL;
	setup_stack(&stack_a, &stack_b, numbers, capacity);
	if (check_is_duplicated(stack_a))
	{
		free_stack(stack_a, stack_b);
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	if (!isasorted(stack_a))
		detect_sort(stack_a, stack_b);
	free_2d_array(numbers);
	free_stack(stack_a, stack_b);
	return (0);
}
