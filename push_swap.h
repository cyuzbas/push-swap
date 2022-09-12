/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/30 16:48:48 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/12 21:26:38 by cicekyuzbas   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stddef.h>
# include <stdio.h>

# define false 0
# define true 1
# define max_int 2147483647
# define min_int -2147483648

typedef struct s_stack
{
	int				value;
	int				index;
	int				order;
	int				target_ord;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}				t_stack;

int		is_sorted(t_stack *stack);
int		is_valid(char **argv);
void	ft_error(void);
void	free_stack(t_stack **stack);

void	sort_small(t_stack **stack);

void	fill_index(t_stack *stack_a, int size);
t_stack	*fill_stack(int argc, char **argv);
t_stack	*ft_stacknew(int value);
t_stack *ft_stacklast(t_stack *stack);
void	ft_stadd_back(t_stack **stack, int value);

void	sa(t_stack **stack_a);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);

#endif