/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/30 16:48:41 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/09/16 19:47:18 by cyuzbas       ########   odam.nl         */
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
		if (value > MAX_INT || value < MIN_INT)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static int	is_duplicated(char **argv)
{
	int	i;
	int	j;
	int	value;
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
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
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
		return (FALSE);
	return (TRUE);
}

int	is_valid(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (FALSE);
		i++;
	}
	if (is_duplicated(argv) || is_overflow(argv))
		return (FALSE);
	return (TRUE);
}
