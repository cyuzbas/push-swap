/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3_4_5.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 12:04:15 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/06 12:05:53 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack)
{
	if (is_sorted(stack))
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
