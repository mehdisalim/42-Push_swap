#include "push_swap.h"

t_stack *oncreate(int capacity)
{
    t_stack *stack = ft_calloc(1, sizeof(t_stack));
    if (!stack)
    {
        ft_putendl_fd("Malloc faild", 2);
        exit(1);
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->stack = ft_calloc(capacity, sizeof(int));
    stack->tmp_arr = ft_calloc(stack->capacity, sizeof(int));
    if (!stack->stack || !stack->tmp_arr)
    {
        ft_putendl_fd("Malloc faild", 2);
        exit(1);
    }
    return (stack);
}

int isFull(t_stack *stack)
{
    if (stack->top >= stack->capacity)
        return (1);
    return (0);
}

int isEmpty(t_stack *stack)
{
    if (stack->top == -1)
        return (1);
    return (0);
}

void    push(t_stack *stack, int content)
{
    if (isFull(stack) || !stack->stack)
        return ;
    stack->stack[++stack->top] = content;
}

int    pop(t_stack *stack)
{
   if (isEmpty(stack) || !stack->stack)
        return 0;
    int value = stack->stack[stack->top];
    stack->stack[stack->top] = 0;
    stack->top--;
    return (value);
}