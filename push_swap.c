/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/30 16:48:45 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/19 18:08:29 by cicekyuzbas   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_stack *head)
{
	t_stack	*current;

	current = head;
	if (!head)
	{
		printf("bos\n");
		return ;
	}
	while (current != NULL )
	{
		printf("%d ", current -> value);
		current = current->next;
	}
	printf("\nindex a = ");
	current = head;
	while (current != NULL )
	{
		printf("%d ", current -> index);
		current = current->next;
	}
	printf("\n");
	free(current);
}

// void    check_leaks()
//  {
//      system ("leaks push_swap");
//  }

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
	if (argc == 4 && !is_sorted(stack_a))
		sort_small(&stack_a);
	fill_index(stack_a, (argc - 1), MIN_INT);
	if (argc > 4 && !is_sorted(stack_a))
		sort_large(&stack_a, &stack_b, (argc - 1));
	// printlist(stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	// atexit(check_leaks);
	return (0);
}
