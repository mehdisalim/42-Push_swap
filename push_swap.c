#include "push_swap.h"

#define TRUE 1
#define FALSE 0

int issorted(t_stack *stack_a)
{
    int *arr = stack_a->stack;
    int i = 0;
    while (arr[i])
    {
        if (arr[i + 1] && arr[i] > arr[i + 1])
            return (FALSE);
        i++;
    }
    return (TRUE);
}

void    detect_sort(t_stack *stack_a, t_stack *stack_b, int *iter)
{
    if (stack_a->capacity == 2)
        sort_two(stack_a, iter);
    else if (stack_a->capacity == 3)
        sort_three(stack_a, iter);
    else if (stack_a->capacity == 4)
        sort_four(stack_a, stack_b, iter);
}

void    sort_two(t_stack *stack_a, int *iter)
{
    if (stack_a->stack[0] > stack_a->stack[1])
    {
        sa(stack_a);
        *iter += 1;
    }
}

void    sort_three(t_stack *stack_a, int *iter)
{
    int *arr = stack_a->stack;
    if ((arr[0] > arr[1] && arr[1] < arr[2]) || (arr[2] > arr[1] && arr[2] < arr[0]))
    {
        ra(stack_a);
        *iter += 1;
    }
    else if ((arr[0] > arr[2] && arr[2] > arr[1]) || (arr[2] < arr[0] && arr[0] > arr[1]))
    {
        rra(stack_a);
        *iter += 1;
    }
    else if ((arr[1] < arr[0] && arr[0] > arr[2]) || (arr[0] < arr[1] && arr[1] > arr[2]))
    {
        sa(stack_a);
        *iter += 1;
    }
    if (!(arr[0] < arr[1] && arr[1] < arr[2]))
        sort_three(stack_a, iter);
    return ;
}

void sort_four(t_stack *stack_a, t_stack *stack_b, int *iter)
{
    int i = 0;
    int hieghest;
    int j = 0;
    while (issorted(stack_a) == TRUE)
    {
       int *arr = stack_a->stack;
       hieghest = arr[0];
       j = 0;
       if (stack_a->top == 2)
       {
           sort_three(stack_a, iter);
           break ;
       }
	   while (i < 4)
       {
	       if (hieghest < arr[i])
           {
              hieghest = arr[i];
              j = i;
           }
           i++;
       }
	   if (j == 3)
	       pa(stack_a, stack_b);
	   if (j == 2)
	       sa(stack_a);
	   if (j == 1)
	       rra(stack_a);
	   if (j == 0)
	       ra(stack_a);
    }
    sort_three(stack_a, iter);
    if (issorted(stack_a) && !isEmpty(stack_b))
        pb(stack_b, stack_a);
    
}
