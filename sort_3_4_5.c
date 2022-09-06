#include "push_swap.h"

void sort_3(t_stack **stack)
{
    if (is_sorted(stack))
        return ;
    if ((*stack)->value > (*stack)->next->value\
        &&(*stack)->value > (*stack)->next->next->value)
    {
        ra(stack);
        // if ((*stack)->value > (*stack)->next->value)
        //     sa(stack);
    }
    else if ((*stack)->value < (*stack)->next->value)
    {
        rra(stack);
        // if ((*stack)->value > (*stack)->next->next->value)
        //     sa(stack);
    }
    if ((*stack)->value > (*stack)->next->value\
        &&(*stack)->value < (*stack)->next->next->value)
        sa(stack);
}