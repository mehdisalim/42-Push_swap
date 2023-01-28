#include "push_swap.h"

#define TRUE 1
#define FALSE 0

int issorted(t_stack *stack_a)
{
    int *arr = stack_a->stack;
    int i = 0;
    while (arr[i])
    {
        if (arr[i + 1] && arr[i] < arr[i + 1])
            return (FALSE);
        i++;
    }
    return (TRUE);
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
}

void    sort_two(t_stack *stack_a)
{
    if (stack_a->stack[0] < stack_a->stack[1])
        sa(stack_a, 0);
}

void    sort_three(t_stack *stack_a)
{
    int *arr = stack_a->stack;
    if (arr[2] > arr[1] && arr[0] > arr[1] && arr[2] < arr[0])
        sa(stack_a, 0);
    if (arr[2] > arr[1] && arr[1] > arr[0])
    {
        sa(stack_a, 0);
        ra(stack_a, 0);
    }
    if (arr[2] > arr[1] && arr[0] > arr[1] && arr[2] > arr[0])
        ra(stack_a, 0);
    if (arr[2] < arr[1] && arr[0] < arr[1] && arr[2] < arr[0])
    {
        sa(stack_a, 0);
        ra(stack_a, 0);
    }
    if (arr[2] < arr[1] && arr[0] < arr[1] && arr[2] > arr[0])
        rra(stack_a, 0);

    return ;
}

int get_index_of_lowest_number(int *arr, int n)
{
    int i = 0;
    int idx = 0;
    int lowest_n = arr[0];
    while (i <= n)
    {
        if (lowest_n > arr[i])
        {
            lowest_n = arr[i];
            idx = i;
        }
        i++;
    }
    return (idx);
}

void    sort_four(t_stack *stack_a, t_stack *stack_b)
{
    int idx;
    if (issorted(stack_a))
        return ;
    idx = get_index_of_lowest_number(stack_a->stack, stack_a->top); 
    if (idx == stack_a->top) 
	    pb(stack_b, stack_a);
    else if (idx == 0)
	{
	    rra(stack_a, 0);
	    pb(stack_b, stack_a);
	}
    else if (idx == 1)
	{
	    rra(stack_a, 0);
	    rra(stack_a, 0);
	    pb(stack_b, stack_a);
	}
    else if (idx == 2)
	{
	    sa(stack_a, 0);
	    pb(stack_b, stack_a);
	}
    sort_three(stack_a);
    while (stack_b->top > -1)
        pa(stack_a, stack_b, 0);
}

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
    int idx ;
    if (issorted(stack_a))
        return ;
	idx = get_index_of_lowest_number(stack_a->stack, stack_a->top);
    if (idx == stack_a->top) 
	    pb(stack_b, stack_a);
    else if (idx == 0)
	{
	    rra(stack_a, 0);
	    pb(stack_b, stack_a);
	}
    else if (idx == 1)
	{
	    rra(stack_a, 0);
	    rra(stack_a, 0);
	    pb(stack_b, stack_a);
	}
    else if (idx == 2)
	{
	    ra(stack_a, 0);
	    sa(stack_a, 0);
	    pb(stack_b, stack_a);
	}
    else if (idx == 3)
	{
	    sa(stack_a, 0);
	    pb(stack_b, stack_a);
	}
    sort_four(stack_a, stack_b);
    pa(stack_a, stack_b, 0);
}
