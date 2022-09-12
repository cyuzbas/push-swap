/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 12:04:15 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/12 11:15:40 by cicekyuzbas   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack **stack)
{
	// if (is_sorted(stack))
	// 	return ;
	// if ((*stack)->value > (*stack)->next->value \
	// 	&& (*stack)->value > (*stack)->next->next->value)
	// 	ra(stack);
	// else if ((*stack)->value < (*stack)->next->value)
	// 	rra(stack);
	if ((*stack)->value > (*stack)->next->value \
		&& (*stack)->value < (*stack)->next->next->value)
		sa(stack);
}
