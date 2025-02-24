/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:18:08 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/23 18:18:09 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **head)
{
	t_stack	*tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tail = *head;
	while (tail->next->next)
		tail = tail->next;
	tail->next->next = *head;
	*head = tail->next;
	tail->next = NULL;
}

void	rra(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		reverse_rotate(stack);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		reverse_rotate(stack);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next && stack_b && *stack_b
		&& (*stack_b)->next)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
	}
}
