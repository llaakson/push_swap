/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:46:01 by llaakson          #+#    #+#             */
/*   Updated: 2024/11/07 15:45:00 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack_node {
	int					cheap;
	int					push_cost;
	int					total;
	int					num;
	int					median;
	int					position;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack;

int		main(int argc, char	**argv);

long	ft_long_atoi(const char *str);
int		is_duplicate(t_stack *stack, t_stack *node);
int		is_sorted(t_stack *a);
int		lstsize(t_stack *stack);
t_stack	*find_last(t_stack *stack);

void	swap_stack(t_stack **stack, int check);
void	rotate_stack(t_stack **stack, int check);
void	reverse_stack(t_stack **stack, int check);
void	push_stack(t_stack **a, t_stack **b, int check);

void	short_three(t_stack **a);
void	check_list_size(t_stack **stack, t_stack **b);

void	check_reverse_a(t_stack **a, t_stack **b);
t_stack	*find_min_num_node(t_stack *stack);
void	find_target_b(t_stack *b, t_stack *a);

t_stack	*find_push_target(t_stack *stack);
t_stack	*find_max_num_node(t_stack *stack);
void	free_array(char **array, int argc);
void	free_list(t_stack **stack);
void	stack_error(t_stack **a, char **array, int argc);

void	check_reverse_b(t_stack **a, t_stack **b);
void	find_target(t_stack *b, t_stack *a);

void	calculate_position(t_stack *stack);
void	calculate_median(t_stack *stack);
void	find_target(t_stack *b, t_stack *a);
void	calculate_cost_b(t_stack *b);
void	calculate_cost_one(t_stack *a);
void	calculate_cost_combined(t_stack *a);

#endif
