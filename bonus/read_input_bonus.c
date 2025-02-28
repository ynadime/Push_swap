/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <ynadime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:57:05 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/27 15:12:31 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

size_t	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	cleanup_and_exit(t_stack **stack_a, t_stack **stack_b, char *input)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free(input);
	write(2, "Error\n", 6);
	exit(1);
}

void	handle_input(t_stack **stack_a, t_stack **stack_b, char *input)
{
	if (ft_strcmp(input, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(input, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(input, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(input, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(input, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(input, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(input, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(input, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(input, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(input, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(input, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		cleanup_and_exit(stack_a, stack_b, input);
	free(input);
}

void	read_input(t_stack **stack_a, t_stack **stack_b)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		handle_input(stack_a, stack_b, input);
		input = get_next_line(0);
	}
	if (is_sorted(*stack_a) && !*stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack_a);
	free_stack(stack_b);
}
