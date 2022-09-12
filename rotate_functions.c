/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 18:27:44 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/12 19:32:52 by cicekyuzbas   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	
	tmp = *stack;
	*stack = (*stack)->next;
	last = ft_stacklast(*stack);
	tmp->next = NULL;
	last->next = tmp;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}