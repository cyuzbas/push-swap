/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 12:06:12 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/16 16:13:38 by cyuzbas       ########   odam.nl         */
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

static void	final_rotate(t_stack **stack_a)
{
	int	lowest_pos;
	int	size;
	int	half_size;

	lowest_pos = lowest_index_order(stack_a);
	size = stack_size(*stack_a);
	half_size = size / 2;
	if (lowest_pos > half_size)
	{
		while (lowest_pos < size)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}

static void	pre_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	size = stack_size(*stack_a);
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
					printf("stack_a = ");
			printlist(*stack_a);
			printf("stack_b = ");
			printlist(*stack_b);
		pushed++;
	}
	sort_small(&(*stack_a));
}

void	sort_large(t_stack **stack_a, t_stack **stack_b, int size)
{
	pre_sort(stack_a, stack_b, size);
	while (*stack_b)
	{
		fill_target(stack_a, stack_b);
		calculate_move(stack_a, stack_b);
		fastest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		final_rotate(stack_a);
}
