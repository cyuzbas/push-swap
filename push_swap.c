/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/30 16:48:45 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/06 18:26:26 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid(char **argv)
{
	return (1);
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
		ft_sa(stack_a);
	if (argc == 4)
		sort_3(stack_a);
	else if (argc > 4)
		sort_large(&stack_a, &stack_b);
	return (0);
}
