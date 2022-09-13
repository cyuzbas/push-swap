/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 12:06:12 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/13 17:34:30 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (TRUE);
}

void	sort_small(t_stack **stack)
{
	if (is_sorted(*stack))
		return ;
	if ((*stack)->value > (*stack)->next->value \
		&& (*stack)->value > (*stack)->next->next->value)
		ra(stack);
	else if ((*stack)->value < (*stack)->next->value)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value \
		&& (*stack)->value < (*stack)->next->next->value)
		sa(stack);
}

// static void	shift_stack(t_stack **stack_a, int size)
// {
// 	int	lowest_pos;
// 	int	half_size;

// 	lowest_pos = get_lowest_index_position(stack_a);
// 	if (lowest_pos > half_size)
// 	{
// 		while (lowest_pos < size)
// 		{
// 			rra(stack_a);
// 			lowest_pos++;
// 		}
// 	}
// 	else
// 	{
// 		while (lowest_pos > 0)
// 		{
// 			ra(stack_a);
// 			lowest_pos--;
// 		}
// 	}
// }

static void	pre_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
	sort_small(&(*stack_a));
}

void	sort_large(t_stack **stack_a, t_stack **stack_b, int size)
{
	pre_sort(stack_a, stack_b, size);
	// while (*stack_b)
	// {
	// 	get_target_position(stack_a, stack_b);
	// 	get_cost(stack_a, stack_b);
	// 	do_cheapest_move(stack_a, stack_b);
	// }
	// if (!is_sorted(*stack_a))
	// 	shift_stack(stack_a, size);
}
