/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/30 16:48:48 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/06 19:06:06 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				order;
	int				target_ord;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

int		is_sorted(t_stack *stack);
void	ft_error(void);
void	free_stack(t_stack **stack);

void	sort_3(t_stack **stack);

t_stack	*fill_stack(int argc, char **argv);

t_stack	*empty_stack(int value);
void	addto_bottom(t_stack **stack, int value);

#endif