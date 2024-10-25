/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:46:01 by llaakson          #+#    #+#             */
/*   Updated: 2024/10/25 23:07:12 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack_node {
	int cheap;
	int push_cost;
	int total;
	int	num;
	int median;
	int position;
	struct s_stack_node *target;
	struct s_stack_node *next;
	struct s_stack_node *prev;
} t_stack;

void print_list(t_stack **stack, t_stack **b); //delete
void    make_node(t_stack **stack, int n);
int	main(int argc, char	**argv);

void    free_array(char **array);
void free_list(t_stack **stack);
int is_duplicate(char **array);
int is_sorted(t_stack *a);
int lstsize(t_stack *stack);
t_stack *find_last(t_stack *stack);

void    swap_stack(t_stack **stack);
void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);

void solver_call_a(t_stack **a, t_stack **b);

void rotate_stack(t_stack **stack, int check);

void reverse_stack(t_stack **stack, int check);

void push_stack(t_stack **a, t_stack **b, int s);

void    short_three(t_stack **a);

t_stack *find_push_target(t_stack *stack);
t_stack *find_max_num_node(t_stack *stack);
void    calculate_position(t_stack *stack);
void    calculate_median(t_stack *stack);
void    find_target(t_stack *b, t_stack *a);
void calculate_cost_b(t_stack *b);
void calculate_cost_one(t_stack *a);
void calculate_cost_combined(t_stack *a);
void push_cheap(t_stack **a, t_stack **b);

t_stack *find_min_num_node(t_stack *stack);

#endif
