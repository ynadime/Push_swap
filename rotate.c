/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:18:16 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/23 18:18:17 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **head)
{
	t_stack	*tail;

	tail = *head;
	while (tail->next)
		tail = tail->next;
	tail->next = *head;
	*head = (*head)->next;
	tail->next->next = NULL;
}

void	ra(t_stack **stack)
{
	if (stack && *stack && (*stack)->next)
	{
		rotate(stack);
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **stack)
{
	if (stack && *stack && (*stack)->next)
	{
		rotate(stack);
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next && stack_b && *stack_b
		&& (*stack_b)->next)
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
	}
}
