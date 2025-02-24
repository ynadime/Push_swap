/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:16:49 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/23 18:16:50 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

size_t	max_position(t_stack **stack)
{
	t_stack	*tmp;
	size_t	current_pos;
	int		max;

	max = find_max(stack);
	tmp = *stack;
	current_pos = 0;
	while (tmp)
	{
		if (tmp->value == max)
			break ;
		current_pos++;
		tmp = tmp->next;
	}
	return (current_pos);
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	size_t	size;

	while (*stack_b)
	{
		size = count_size(*stack_b);
		if ((*stack_b)->value == find_max(stack_b))
			pa(stack_a, stack_b);
		else if (max_position(stack_b) > size / 2)
			rrb(stack_b);
		else
			rb(stack_b);
	}
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b, size_t size, size_t end)
{
	size_t	start;

	start = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index < start)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			if (end < size)
				end++;
			if (start < end)
				start++;
		}
		else if ((*stack_a)->index <= end || (*stack_a)->index == start)
		{
			pb(stack_a, stack_b);
			if (end < size)
				end++;
			if (start < end)
				start++;
		}
		else
			ra(stack_a);
	}
}

void	range_sort(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	size_t	end;
	int		*array;

	if (size <= 100)
		end = size / 5;
	else
		end = 40;
	array = create_index_array(stack_a, size);
	assign_indexes(stack_a, array, size);
	push_to_b(stack_a, stack_b, size, end);
	push_back_to_a(stack_a, stack_b);
	free(array);
}
