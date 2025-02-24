/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:17:22 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/23 18:17:24 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_top(t_stack **stack, int min)
{
	while ((*stack)->value != min)
	{
		if ((*stack)->next->value == min)
			sa(stack);
		else if ((*stack)->next->next->value == min)
			ra(stack);
		else
			rra(stack);
	}
}

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && a > c && b < c)
		ra(stack);
	else if (a < b && a < c && b > c)
	{
		sa(stack);
		ra(stack);
	}
	else if (c < a && c < b && a < b)
		rra(stack);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		min;

	min = (*stack_a)->value;
	tmp = (*stack_a)->next;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	move_min_to_top(stack_a, min);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	t_stack	*tmp;
	int		i;

	i = 0;
	while (i < 2)
	{
		min = (*stack_a)->value;
		tmp = (*stack_a)->next;
		while (tmp)
		{
			if (tmp->value < min)
				min = tmp->value;
			tmp = tmp->next;
		}
		move_min_to_top(stack_a, min);
		pb(stack_a, stack_b);
		i++;
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
