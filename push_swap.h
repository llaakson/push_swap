/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:46:01 by llaakson          #+#    #+#             */
/*   Updated: 2024/10/23 19:35:05 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack_node {
	int	num;
	//char **array_a;
	//char **array_aa;
	//int data;
	struct s_stack_node *temp;
	struct s_stack_node *next;
	struct s_stack_node *prev;
} t_stack;

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

void rotate_stack(t_stack **stack, int check);

void reverse_stack(t_stack **stack);

void push_stack(t_stack **a, t_stack **b, int s);

#endif
