/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:57:23 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/24 16:57:24 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_b && *stack_b)
		push(stack_b, stack_a);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && *stack_a)
		push(stack_a, stack_b);
}
