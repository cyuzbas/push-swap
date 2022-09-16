/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   order.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 12:06:26 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/16 15:03:39 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_target(t_stack **a, int b_idx, int t_idx, int t_ord)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < t_idx)
		{
			t_idx = tmp_a->index;
			t_ord = tmp_a->order;
		}
		tmp_a = tmp_a->next;
	}
	if (t_idx != MAX_INT)
		return (t_ord);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < t_idx)
		{
			t_idx = tmp_a->index;
			t_ord = tmp_a->order;
		}
		tmp_a = tmp_a->next;
	}	
	return (t_ord);
}

static void	current_order(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->order = i;
		tmp = tmp->next;
		i++;
	}
}

int	lowest_index_order(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = MAX_INT;
	current_order(stack);
	lowest_pos = tmp->order;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->order;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

void	fill_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		target_order;

	tmp_b = *stack_b;
	current_order(stack_a);
	current_order(stack_b);
	target_order = 0;
	while (tmp_b)
	{
		target_order = calculate_target(stack_a, \
						tmp_b->index, MAX_INT, target_order);
		tmp_b->target = target_order;
		tmp_b = tmp_b->next;
	}
}
