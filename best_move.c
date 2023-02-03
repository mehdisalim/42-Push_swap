#include "push_swap.h"
/*
void    best_position_in_stack_b(t_stack *stack_b, int value)
{
    int *arr = stack_b->stack;
    int i = 0;
    int res = 0;
    int previes_val = 0;
    int pos = 0;
    while (i < stack_b->capacity)
    {
        res = value - arr[i];
        if (res > 0 && res < previes_val)
        {
            previes_val = arr[i];
            pos = i;
        }
    }
}
*/

int getbigestnumber(t_stack *stack)
{
    int *arr = stack->stack;
    int i = stack->top;
    int lowest = arr[i];
    while (i)
    {
        if (arr[i] > lowest)
            lowest = arr[i];
        i--;
    }
    return (lowest);
}

int getlowestnumber(t_stack *stack)
{
    int *arr = stack->stack;
    int i = stack->top;
    int lowest = arr[i];
    while (i)
    {
        if (arr[i] < lowest)
            lowest = arr[i];
        i--;
    }
    return (lowest);
}

int getlowestnumber_idx(t_stack *stack)
{
    int *arr = stack->stack;
    int i = stack->top;
    int lowest = arr[i];
    int n = 0;
    while (i)
    {
        if (arr[i] < lowest)
        {
            lowest = arr[i];
            n = i;
        }
        i--;
    }
    return (n);
}

int how_many_iteration_in_b(t_stack *stack_b, int value)
{
    int *arr = stack_b->stack;
    int i = stack_b->top;
    int pre_v = stack_b->stack[getlowestnumber_idx(stack_b)];
    //ft_printf("%d\n", pre_v);
    int x = 0;
    if (value < getlowestnumber(stack_b) || value > getbigestnumber(stack_b))
        return 0;
    while (i)
    {
        if (pre_v < arr[i] && arr[i] < value)
        {
            pre_v = arr[i];
            x = i;
        }
        i--;
    }
    //ft_printf("pre_v == %d\n", pre_v);
    if (stack_b->top / 2 < x)
        x = stack_b->top - x;
    else 
        x++; 
    return (x);
}

int how_many_iteration_in_a(int n, int top)
{
    if (top / 2 < n)
        return (top - n + 1);
    return n + 1;
}

int   best_move(t_stack *stack_a, t_stack *stack_b)
{
    int *arr = stack_a->stack;
    //t_stack *tmp_stack = oncreate(stack_a->capacity);
    pb(stack_b, stack_a);
    pb(stack_b, stack_a);
    if (stack_b->stack[0] < stack_b->stack[1])
        sb(stack_b, 0);
    int iter_a;
    int iter_b;
    int i = 0;
    int idx;
    int a = 0;
    int b = 0;
    int middle;
    int y = 0;
    while (y++ < 2)
    {
       middle = stack_a->top / 2;
       i = stack_a->top;
       a = 0;
       b = 0;
	    iter_a = how_many_iteration_in_a(i, stack_a->top);
	    iter_b = how_many_iteration_in_b(stack_b, arr[i]);
        idx = iter_a + iter_b;
	   while (i)
	   {
	       iter_a = how_many_iteration_in_a(i, stack_a->top);
	       iter_b = how_many_iteration_in_b(stack_b, arr[i]);
       //    ft_printf("%d\t == iter ==> %d\n", arr[i], iter_a + iter_b);
           if (iter_a + iter_b < idx)
           {
               a = iter_a;
               b = iter_b;
               idx = a + b;
               y = i;
           }
	       i--;
	   }
       //ft_printf("%d\n", a);
       while (a > -1)
       {
           if (y > middle)
               ra(stack_a, 0);
           else
               rra(stack_a, 0);
           a--;
       }

       while (b > -1)
       {
           if (y > stack_b->top / 2)
               rb(stack_a, 0);
           else
               rrb(stack_a, 0);
           b--;
       }
       pb(stack_b, stack_a);
        int j = 0;
        while (j <= stack_b->top)
            ft_printf("%d\n", stack_b->stack[j++]);
        ft_printf("=========================================\n");
       //while (!isbsorted(stack_b))
           //rrb(stack_b, 0);
    }
    i = 0;
    while (i <= stack_b->top)
        ft_printf("%d\n", stack_b->stack[i++]);
    //if (stack_a->top < 3)
      //  sort_three(stack_a);
    return 0;
}
