/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 18:27:44 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/15 16:01:41 by cicekyuzbas   ########   odam.nl         */
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
	long	value;
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

// void	fill_index(t_stack *stack_a, int size)
// {
// 	t_stack	*tmp;
// 	t_stack	*next_max;
// 	int		current;
// 	int		i;

// 	next_max = NULL;
// 	tmp = stack_a;
// 	while (size > 0)
// 	{
// 		current = MIN_INT;
// 		i = 0;
// 		while (tmp && tmp->next && i < (size - 1))
// 		{
// 			if (tmp->value > tmp->next->value)
// 			{
// 				next_max = tmp;
// 			}
// 			tmp = tmp->next;
// 			printf("afterloop- size = %d, value = %d, index = %d\n", size, tmp->value, tmp->index);
// 			i++;
// 		}
// 		if (next_max != NULL)
// 			next_max->index = size;
// 		printf("size = %d, value = %d, index = %d\n", size, tmp->value, tmp->index);
// 		size--;
// 		tmp = tmp->next;
// 	}
// }

// void	fill_index(t_stack *stack_a, int size)
// {
// 	t_stack	*tmp;
// 	t_stack	*min;
// 	int		new;
// 	int		i;

// 	i = 1;
// 	while (i <= size)
// 	{
// 		tmp = stack_a;
// 		new = MAX_INT;
// 		min = NULL;
// 		while (tmp)
// 		{
// 			if (tmp->value < new && tmp->index == 0)
// 			{
// 				new = tmp->value;
// 				min = tmp;
// 				tmp = 
// 			}
// 		}
		
// 	}
		
// }

void	fill_index(t_stack *stack_a, int size)
{
	t_stack	*tmp;
	t_stack	*max;
	int		min;

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
