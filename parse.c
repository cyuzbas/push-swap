/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 18:27:44 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/06 19:06:33 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*empty_stack(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->order = -1;
	new->target_ord = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	addto_bottom(t_stack **stack, int value)
{
	t_stack	*tmp;
	t_stack	*new;

	new = empty_stack(value);
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = ft_lstlast(*stack);
	tmp->next = new;
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	value;
	int			i;

	value = 0;
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (i == 1)
			stack_a = empty_stack(value);
		else
			addto_bottom(&stack_a, value);
		i++;
	}
	return (stack_a);
}
