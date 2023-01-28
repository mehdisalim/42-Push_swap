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
    (void) stack_b;
    if (stack_a->capacity == 2)
        sort_two(stack_a, iter);
    else if (stack_a->capacity == 3)
        sort_three(stack_a, iter);
   else if (stack_a->capacity == 5)
        sort_five(stack_a, stack_b, iter);
}

void    sort_two(t_stack *stack_a, int *iter)
{
    if (stack_a->stack[0] > stack_a->stack[1])
    {
        sa(stack_a, 0);
        *iter += 1;
    }
}

void    sort_three(t_stack *stack_a, int *iter)
{
    int *arr = stack_a->stack;
    if (arr[0] > arr[1] && arr[1] < arr[2])
    {
        ra(stack_a, 0);
        *iter += 1;
    }
    else if (arr[0] > arr[2] && arr[2] > arr[1])
    {
        rra(stack_a, 0);
        *iter += 2;
    }
    else if (arr[1] < arr[0] && arr[0] > arr[2])
    {
        sa(stack_a, 0);
        *iter += 1;
    }
    else if (arr[2] > arr[1] && arr[2] < arr[0])
    {
        ra(stack_a, 0);
        sa(stack_a, 0);
        *iter += 2;
    }
    else if (arr[2] < arr[0] && arr[0] > arr[1])
    {
        rra(stack_a, 0);
        *iter += 1;
    }
    if (!(arr[0] < arr[1] && arr[1] < arr[2]))
        sort_three(stack_a, iter);
    return ;
}

int get_index_of_lowest_number(int *arr)
{
    int i = 0;
    int idx = 0;
    int lowest_n = arr[0];
    while (arr[i])
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

void sort_five(t_stack *stack_a, t_stack *stack_b, int *iter)
{
    int idx ;
    while (stack_a->top > 2)
   {
	   idx = get_index_of_lowest_number(stack_a->stack);
	   if (idx == 0)
	   {
	       rra(stack_a, 0);
	       pb(stack_b, stack_a);
           *iter += 2;
	   }
	   if (idx == 1)
	   {
	       rra(stack_a, 0);
	       rra(stack_a, 0);
	       pb(stack_b, stack_a);
           *iter += 3;
	   }
	   if (idx == 2)
	   {
	       ra(stack_a, 0);
	       sa(stack_a, 0);
	       pb(stack_b, stack_a);
           *iter += 3;
	   }
	   if (idx == 3)
	   {
	       sa(stack_a, 0);
	       pb(stack_b, stack_a);
           *iter += 2;
	   }
	   if (idx == 4)
       {
	       pb(stack_b, stack_b);
           *iter += 2;
       }
    }
    sort_three(stack_a, iter);
    return ;
    while (!isEmpty(stack_b))
    {
        pa(stack_a, stack_b, 0);
        *iter += 1;
    }
}
