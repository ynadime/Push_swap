/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:57:37 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/24 16:57:38 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		rotate(stack);
}

void	rb(t_stack **stack)
{
	if (stack && *stack && (*stack)->next)
		rotate(stack);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next && stack_b && *stack_b
		&& (*stack_b)->next)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}
