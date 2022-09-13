/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/30 16:48:48 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/13 14:43:07 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stddef.h>
# include <stdio.h>

# define FALSE 0
# define TRUE 1
# define MAX_INT 2147483647
# define MIN_INT -2147483648

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
void	sort_large(t_stack **stack_a, t_stack **stack_b, int size);

void	fill_index(t_stack *stack_a, int size);
t_stack	*fill_stack(int argc, char **argv);
t_stack	*ft_stacknew(int value);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stadd_back(t_stack **stack, int value);

void	sa(t_stack **stack_a);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);

#endif