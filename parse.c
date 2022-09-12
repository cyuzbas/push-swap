/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 18:27:44 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/12 21:28:20 by cicekyuzbas   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_stacklast(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_stacknew(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	// new->index = 0;
	// new->order = -1;
	// new->target_ord = -1;
	// new->cost_a = -1;
	// new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	ft_stadd_back(t_stack **stack, int value)
{
	t_stack	*tmp;
	t_stack	*next;

	next = ft_stacknew(value);
	if (!next)
		return ;
	if (!*stack)
	{
		*stack = next;
		return ;
	}
	tmp = ft_stacklast(*stack);
	tmp->next = next;
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	long 	value;
	int		i;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (i == 1)
			stack_a = ft_stacknew(value);
		else
			ft_stadd_back(&stack_a, value);
		i++;
	}
	return (stack_a);
}

void	fill_index(t_stack *stack_a, int size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--size > 0)
	{
		ptr = stack_a;
		value = min_int;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == min_int && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}