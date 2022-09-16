/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 18:27:44 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/16 19:13:04 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *stack)
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
	new->index = 0;
	new->order = -1;
	new->target = -1;
	new->move_a = -1;
	new->move_b = -1;
	new->next = NULL;
	return (new);
}

void	ft_stadd_back(t_stack **stack, int value)
{
	t_stack	*tmp;
	t_stack	*next;

	next = ft_stacknew(value);
	if (!next)
	{
		free_stack(stack);
		ft_error();
	}	
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
	long	value;
	int		i;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (i == 1)
		{
			//burda null donerse program calismaya devame diyor. Bunu engelledik!
			stack_a = ft_stacknew(value);
			if (!stack_a)
				return (NULL);
		}
		else
			ft_stadd_back(&stack_a, value);
		i++;
	}
	return (stack_a);
}

void	fill_index(t_stack *stack_a, int size, int min)
{
	t_stack	*tmp;
	t_stack	*max;

	while (size > 0)
	{
		tmp = stack_a;
		min = MIN_INT;
		max = NULL;
		while (tmp)
		{
			if (tmp->value == MIN_INT && tmp->index == 0)
				tmp->index = 1;
			if (tmp->value > min && tmp->index == 0)
			{
				min = tmp->value;
				max = tmp;
				tmp = stack_a;
			}
			else
				tmp = tmp->next;
		}
		if (max != NULL)
			max->index = size;
		size--;
	}
}
