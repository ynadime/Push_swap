/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <ynadime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:19:29 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/24 14:27:04 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	size_t			index;
	struct s_stack	*next;
}					t_stack;

int					ft_atoi(const char *str, char **tokens);
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
size_t				arg_has_no_digits(char **av);
size_t				has_invalid_argument(char **tokens);
size_t				has_overflow(char **tokens);
size_t				has_duplicates(char **tokens);
void				free_stack(t_stack **stack);
void				free_tokens(char **tokens);
void				sort(t_stack **stack_a, t_stack **stack_b);
void				sort_three(t_stack **stack);
void				sort_four(t_stack **stack_a, t_stack **stack_b);
void				sort_five(t_stack **stack_a, t_stack **stack_b);
void				assign_indexes(t_stack **stack, int *array, size_t size);
void				bubble_sort(int *array, size_t size);
int					*create_index_array(t_stack **stack, size_t size);
void				range_sort(t_stack **stack_a, t_stack **stack_b,
						size_t size);
size_t				count_size(t_stack *stack);

void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				sa(t_stack **stack);
void				sb(t_stack **stack);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack);
void				rb(t_stack **stack);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack);
void				rrb(t_stack **stack);
void				rrr(t_stack **stack_a, t_stack **stack_b);

#endif
