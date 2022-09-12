/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/30 16:48:41 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/11 21:47:44 by cicekyuzbas   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_overflow(char **argv)
{
	int		i;
	long	value;

	i = 1;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		if (value > max_int || value < min_int)
				return (true);
		i++;
	}
	return (false);
}

static int	is_duplicated(char **argv)
{
	int i;
	int j;
	int value;
	int	tmp;

	i = 1;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		j = 1;
		while (argv[j])
		{
			tmp = ft_atoi(argv[j]);
			if (i != j && value == tmp)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static int	is_number(char *n)
{
	int	i;

	i = 0;
	if (ft_strcmp(n, ""))
		return (0);
	if ((n[i] == '+' || n[i] == '-') && n[i] && n[i + 1] != '\0')
		i++;
	while (n[i] && ft_isdigit(n[i]))
		i++;
	if (n[i] && !ft_isdigit(n[i]))
		return (false);
	return (true);
}

int	is_valid(char **argv)
{
	int i;
	int	value;
	
	i = 1;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (false);
		i++;
	}
	if (is_duplicated(argv) || is_overflow(argv))
		return (false);
	return (true);
}