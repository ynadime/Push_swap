/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:58:39 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/24 16:58:40 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**split_arguments(char **av)
{
	char	*str;
	char	*tmp;
	char	**tokens;
	size_t	i;

	str = ft_strdup(av[1]);
	if (!str)
		return (NULL);
	i = 2;
	while (av[i])
	{
		tmp = str;
		str = ft_strjoin(str, " ");
		free(tmp);
		if (!str)
			return (NULL);
		tmp = str;
		str = ft_strjoin(str, av[i++]);
		free(tmp);
		if (!str)
			return (NULL);
	}
	tokens = ft_split(str, ' ');
	free(str);
	return (tokens);
}

void	add_to_stack(t_stack *head, int value, char **tokens)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
	{
		free_tokens(tokens);
		exit(1);
	}
	new->value = value;
	new->next = NULL;
	while (head->next)
		head = head->next;
	head->next = new;
}

void	innit_stack_a(t_stack **stack_a, char **tokens)
{
	size_t	i;

	i = 0;
	*stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!*stack_a)
	{
		free_tokens(tokens);
		exit(1);
	}
	i = 0;
	(*stack_a)->value = ft_atoi(tokens[i], tokens);
	(*stack_a)->next = NULL;
	i++;
	while (tokens[i])
	{
		add_to_stack(*stack_a, ft_atoi(tokens[i], tokens), tokens);
		i++;
	}
}

int	main(int ac, char **av)
{
	char	**tokens;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		exit(0);
	if (arg_has_no_digits(av))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	tokens = split_arguments(av);
	if (!tokens)
		exit(1);
	if (has_invalid_argument(tokens) || has_duplicates(tokens))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	innit_stack_a(&stack_a, tokens);
	stack_b = NULL;
	free_tokens(tokens);
	read_input(&stack_a, &stack_b);
}
