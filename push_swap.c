/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/30 16:48:45 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/20 13:33:25 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	fill_index(stack_a, (argc - 1));
	if (argc > 4 && !is_sorted(stack_a))
		sort_large(&stack_a, &stack_b, (argc - 1));
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
