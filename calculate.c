/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 12:06:26 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/20 13:30:45 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a(t_stack **a, int *move)
{
	while (*move)
	{
		if (*move > 0)
		{
			ra(a);
			(*move)--;
		}
		else if (*move < 0)
		{
			rra(a);
			(*move)++;
		}
	}
}

static void	rotate_b(t_stack **b, int *move)
{
	while (*move)
	{
		if (*move > 0)
		{
			rb(b);
			(*move)--;
		}
		else if (*move < 0)
		{
			rrb(b);
			(*move)++;
		}
	}
}

static void	ft_move(t_stack **a, t_stack **b, int move_a, int move_b)
{
	if (move_a < 0 && move_b < 0)
	{
		while (move_a < 0 && move_b < 0)
		{
			move_a++;
			move_b++;
			rrr(a, b);
		}
	}
	else if (move_a > 0 && move_b > 0)
	{
		while (move_a > 0 && move_b > 0)
		{
			move_a--;
			move_b--;
			rr(a, b);
		}
	}
	rotate_a(a, &move_a);
	rotate_b(b, &move_b);
	pa(a, b);
}

void	fastest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		fastest;
	int		total_move;
	int		move_a;
	int		move_b;

	tmp = *stack_b;
	fastest = MAX_INT;
	while (tmp)
	{
		total_move = ft_abs(tmp->move_a) + ft_abs(tmp->move_b);
		if (total_move < ft_abs(fastest))
		{
			fastest = total_move;
			move_a = tmp->move_a;
			move_b = tmp->move_b;
		}
		tmp = tmp->next;
	}
	ft_move(stack_a, stack_b, move_a, move_b);
}

void	calculate_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = stack_size(tmp_a);
	size_b = stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->move_b = tmp_b->order;
		if (tmp_b->order > size_b / 2)
			tmp_b->move_b = (size_b - tmp_b->order) * -1;
		tmp_b->move_a = tmp_b->target;
		if (tmp_b->target > size_a / 2)
			tmp_b->move_a = (size_a - tmp_b->target) * -1;
		tmp_b = tmp_b->next;
	}
}
