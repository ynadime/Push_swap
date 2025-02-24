/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:17:46 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/23 18:17:47 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indexes(t_stack **stack, int *array, size_t size)
{
	size_t	i;
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->value == array[i])
				tmp->index = i;
			i++;
		}
		tmp = tmp->next;
	}
}

void	bubble_sort(int *array, size_t size)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*create_index_array(t_stack **stack, size_t size)
{
	size_t	i;
	t_stack	*tmp;
	int		*array;

	tmp = *stack;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
	{
		free_stack(stack);
		exit(1);
	}
	i = 0;
	while (i < size)
	{
		array[i++] = tmp->value;
		tmp = tmp->next;
	}
	bubble_sort(array, size);
	return (array);
}
