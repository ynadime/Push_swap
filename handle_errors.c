/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <ynadime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:18:00 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/27 15:07:37 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_has_overflow(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		ft_atoi(tokens[i++], tokens);
}

size_t	arg_has_no_digits(char **av)
{
	int	i;
	int	j;
	int	digits;

	i = 1;
	while (av[i])
	{
		digits = 0;
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				digits++;
			j++;
		}
		if (digits == 0)
			return (1);
		i++;
	}
	return (0);
}

size_t	has_invalid_argument(char **tokens)
{
	int	i;
	int	j;

	i = 0;
	while (tokens[i])
	{
		j = 0;
		if (tokens[i][j] == '+' || tokens[i][j] == '-')
			j++;
		if (!tokens[i][j])
			return (free_tokens(tokens), 1);
		while (tokens[i][j])
		{
			if (tokens[i][j] < '0' || tokens[i][j] > '9')
				return (free_tokens(tokens), 1);
			j++;
		}
		i++;
	}
	return (0);
}

size_t	has_duplicates(char **tokens)
{
	int	i;
	int	j;

	i = 0;
	while (tokens[i])
	{
		j = i + 1;
		while (tokens[j])
		{
			if (ft_atoi(tokens[i], tokens) == ft_atoi(tokens[j], tokens))
			{
				free_tokens(tokens);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
