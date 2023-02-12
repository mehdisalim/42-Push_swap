#include "push_swap.h"

int isasorted(t_stack *stack_a)
{
    int *arr = stack_a->stack;
    int i = 0;
    while (i < stack_a->capacity)
    {
        if (i + 1 <= stack_a->capacity && arr[i] < arr[i + 1])
            return (0);
        i++;
    }
    return (1);
}

int isbsorted(t_stack *stack_b)
{
    int *arr = stack_b->stack;
    int i = 0;
    while (i <= stack_b->top)
    {
        if (i + 1 <= stack_b->top && arr[i] > arr[i + 1])
            return (0);
        i++;
    }
    return (1);
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