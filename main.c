/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:27:44 by esalim            #+#    #+#             */
/*   Updated: 2023/01/27 13:10:23 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av);

void    decoration(t_stack *stack_a, t_stack *stack_b, int iteration)
{
    int i;
    system("clear");
    printf("operations :\n");
    printf("\n0\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\t13\n");
    printf("sa\tsb\tss\tpa\tpb\tra\trb\trr\trra\trrb\trrr\treset\tsort\targs\n");
    printf("==========================================================\n");
    i = stack_a->capacity;
    while (--i > -1)
        printf("stack_a\t%i\t==>\t%d\t|\tstack_b\t%i\t==>\t%d\t\n", i, stack_a->stack[i], i, stack_b->stack[i]);
    printf("\ntotal iteration is : %i\n", iteration);
}

void    send_args()
{
    int ac;
    printf("ac : ");
    scanf("%d", &ac);
    printf("argv : \n");
    int i = 1;
    char **arr = malloc(ac * 8);
    arr[0] =  ft_strdup("a.out");
    while (i <= ac)
    {
        char str[20];
        scanf("%s", str);
        arr[i] = ft_strdup(str);
        i++;
    }
    main(ac, arr);
}

void    setup_stack(t_stack **stack_a, t_stack **stack_b, char **numbers, int capacity)
{
    int i = -1;
    *stack_a = oncreate(capacity);
    *stack_b = oncreate(capacity);
    clear(*stack_a);
    clear(*stack_b);
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

int main(int ac, char **av)
{
    char    *args = get_all_args(ac, av);
    char    **numbers = ft_split(args, ' ');
    int capacity = get_num_count(numbers); 
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    int i;
    int iteration;
begin:
    iteration = 0;
    i = -1;
    setup_stack(&stack_a, &stack_b, numbers, capacity);
    decoration(stack_a, stack_b, iteration);
    while (1)
    {
	   int j;
	   i = 0;
	   printf("\nEnter your operation: ");
	   scanf("%d", &j);
	   printf("\n");
	   switch(j)
	   {
	       case 0:
	           sa(stack_a);
               iteration++;
	           break ;
	       case 1:
	           sb(stack_b);
               iteration++;
	           break ;
	       case 2:
	           ss(stack_a, stack_b);
               iteration++;
	           break ;
	       case 3:
	           pa(stack_a, stack_b);
               iteration++;
	           break ;
	       case 4:
	           pb(stack_b, stack_a);
               iteration++;
	           break ;
	       case 5:
	           ra(stack_a);
               iteration++;
	           break ;
	       case 6:
	           rb(stack_b);
               iteration++;
	           break ;
	       case 7:
	           rr(stack_a, stack_b);
               iteration++;
	           break ;
	       case 8:
	           rra(stack_a);
               iteration++;
	           break ;
	       case 9:
	           rrb(stack_b);
               iteration++;
	           break ;
	       case 10:
	           rrr(stack_a, stack_b);
               iteration++;
	           break ;
           case 11:
               goto begin; 
               break ;
           case 12:
               sort_three(stack_a, &iteration);
               break ;
           case 13:
               send_args();
	       default:
	           break ;
	   }
       decoration(stack_a, stack_b, iteration);
    }
    return (0);
}
