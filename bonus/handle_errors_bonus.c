/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:56:54 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/24 16:56:57 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		while (tokens[i][j])
		{
			if (tokens[i][j] < '0' || tokens[i][j] > '9')
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
