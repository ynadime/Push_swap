/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:58:01 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/24 16:58:02 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "GNL/get_next_line.h"
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
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				arg_has_no_digits(char **av);
size_t				has_invalid_argument(char **tokens);
size_t				has_overflow(char **tokens);
size_t				has_duplicates(char **tokens);
void				free_stack(t_stack **stack);
void				free_tokens(char **tokens);
void				assign_indexes(t_stack **stack, int *array, size_t size);
size_t				count_size(t_stack *stack);
void				read_input(t_stack **stack_a, t_stack **stack_b);
int					ft_strcmp(const char *s1, const char *s2);

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
