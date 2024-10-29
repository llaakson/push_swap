/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:23:51 by llaakson          #+#    #+#             */
/*   Updated: 2024/10/29 18:49:24 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void solver_call(t_stack **a, t_stack **b)
{
	calculate_median(*a);
	calculate_median(*b);
	calculate_position(*a);
	calculate_position(*b);
	find_target(*b,*a);
	calculate_cost_one(*a);
	calculate_cost_b(*b);
	calculate_cost_combined(*a);	
	push_cheap(a,b);
}
void check_stack_b_mins(t_stack **b)
{
	int min;
	int max;

	max = (*b)->num;
	if (max > (*b)->next->num)
		min = (*b)->next->num;
	else
	{
		max = (*b)->next->num;
		min = (*b)->num;
	}
	if ((*b)->num == min)
		rotate_stack(b,2);
}

void solve_over_three(t_stack **a, t_stack **b)
{
	// blindly push first two b stack
	push_stack(a, b, 1);
	push_stack(a, b, 1);
	while (lstsize(*a) != 3)
		solver_call(a,b);
	short_three(a);
	while (lstsize(*b) != 0)	
		solver_call_a(a,b);
	t_stack *blah = find_min_num_node(*a);
	calculate_median(blah);
	while ((*a)->num > blah->num)
	{
		if (blah->median == 1)
			rotate_stack(a,1);
		else if (blah->median == 0)
			reverse_stack(a,1);
	}
}
void	make_node(t_stack **stack, int n)
{
	t_stack *node;
	t_stack *last_node;

	node = malloc(sizeof(t_stack));
	if (!(node))
		return ;
	node->next = NULL;
	node->num = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	make_stack(t_stack **a, char **array)
{
	int n; 
	int i;

	i = 0;
	while (array[i])
	{
		n = ft_atoi(array[i]);
		make_node(a, n);
		i++;
	}
	
}

void print_list(t_stack **stack, t_stack **b)
{
	t_stack *print_node;
	t_stack *print_b;
	
	print_node = (*stack);
	ft_printf("stack a: ");
	while (print_node != NULL)
	{
		ft_printf("%d ", print_node->num);
		print_node = print_node->next;
	}
	ft_printf("\n");
	print_b = (*b);
	ft_printf("stack b: ");
	while (print_b != NULL)
	{
		ft_printf("%d ", print_b->num);
		print_b = print_b->next;
	}
	ft_printf("\n");	
}

void	check_list_size(t_stack **stack, t_stack **b)
{
	int size;

	size = lstsize(*stack);
	if (size == 2)
		sa(stack);
	if (size == 3)
		short_three(stack);
	if (size > 3)
		solve_over_three(stack, b);
}

char **make_array(int argc, char **argv)
{	
	char **array;
	int i;

	array = NULL;	
	i = 0;
	if (argc == 2)
	{
		array = ft_split(argv[1],' ');
		return (array);
	}
	else
		array = (argv+1); // malloc thiiss
	return (array);
	
}
int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	char **array;

	a = NULL;
	b = NULL;
	array = NULL;
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc >= 2)
		array = make_array(argc, argv);
	if (!(is_duplicate(array)))
	{
		write(2,"Error\n",6);
		return (1);
	}
	make_stack(&a, array);
	if (!(is_sorted(a)))
		check_list_size(&a, &b);
	//print_list(&a, &b);
	//free_array(array);
	free_list(&a);

	return (0);
}
