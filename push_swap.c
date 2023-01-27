#include "push_swap.h"

void    sort_three(t_stack *stack_a, int *iter)
{
    int *arr = stack_a->stack;
    if (arr[0] > arr[1] && arr[1] < arr[2])
    {
        ra(stack_a);
        *iter += 1;
    }
    else if (arr[0] > arr[2] && arr[2] > arr[1])
    {
        rra(stack_a);
        *iter += 2;
    }
    else if (arr[1] < arr[0] && arr[0] > arr[2])
    {
        sa(stack_a);
        *iter += 1;
    }
    else if (arr[2] > arr[1] && arr[2] < arr[0])
    {
        ra(stack_a);
        sa(stack_a);
        *iter += 2;
    }
    else if (arr[2] < arr[0] && arr[0] > arr[1])
    {
        rra(stack_a);
        *iter += 1;
    }
    if (!(arr[0] < arr[1] && arr[1] < arr[2]))
        sort_three(stack_a, iter);
    return ;
}
/*
int sortfour(t_stack *stack_a, int *iter)
{
    int *arr = stack_a->stack;
    int i = 0;
    int hieghest = arr[0];
    int j = 0;
    while (i < 4)
    {
        if (hieghest < arr[i])
        {
            j = i;
            hieghest = arr[i];
        }
        i++;
    }
    if (i == 4)
    {
        pa(stack_a, stack_b);
    }
}*/
