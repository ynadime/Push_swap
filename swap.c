/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:18:48 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/23 18:18:50 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	int	tmp;

	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

void	sa(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		swap(stack);
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		swap(stack);
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		swap(stack_a);
		swap(stack_b);
		write(1, "ss\n", 3);
	}
}
