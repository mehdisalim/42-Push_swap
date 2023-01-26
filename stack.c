#include "push_swap.h"

t_stack *oncreate(int capacity)
{
    t_stack *stack = malloc(sizeof(t_stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->stack = malloc(capacity * 4);
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

void    pop(t_stack *stack)
{
   if (isEmpty(stack) || !stack->stack)
        return ;
    stack->stack[stack->top] = 0;
    stack->top--;
}

void    clear(t_stack *stack)
{
    while (!isEmpty(stack))
        pop(stack);
}
