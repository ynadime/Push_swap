/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <ynadime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:19:49 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/24 14:26:37 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(const char *str, char **tokens)
{
	size_t	i;
	int		sign;
	long	results;

	i = 0;
	sign = 1;
	results = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		results = (results * 10) + (str[i++] - '0');
		if (results * sign > INT_MAX || results * sign < INT_MIN)
		{
			free_tokens(tokens);
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	return (results * sign);
}
