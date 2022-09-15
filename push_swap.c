/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/30 16:48:45 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/15 14:25:13 by cicekyuzbas   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_stack *head)
{
	t_stack	*current;

	current = head;
	if (!head)
		return ;
	while (current != NULL )
	{
		printf("%d", current -> value);
		current = current->next;
	}
	printf("\n");
	current = head;
	while (current != NULL )
	{
		printf("%d", current -> index);
		current = current->next;
	}
	printf("\n");
	free(current);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	if (argc < 2)
		return (0);
	if (!is_valid(argv))
		ft_error();
	stack_a = fill_stack(argc, argv);
	if (stack_a == NULL)
		ft_error();
	stack_b = NULL;
	if (argc == 3 && !is_sorted(stack_a))
		sa(&stack_a);
	if (argc == 4)
		sort_small(&stack_a);
	fill_index(stack_a, (argc - 1));
	if (argc > 4)
		sort_large(&stack_a, &stack_b, (argc - 1));
	printlist(stack_a);
	printlist(stack_b);
	return (0);
}
