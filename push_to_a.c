/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:41:08 by llaakson          #+#    #+#             */
/*   Updated: 2024/10/26 21:24:15 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_cheap_b(t_stack **a, t_stack **b)
{
	t_stack *node;

	node = find_push_target(*b);
	
	if (node->target->median == 0)
	{
		while (node->target->push_cost != 0)
		{
			reverse_stack(a,1);
			node->target->push_cost -= 1;
		}
	}
	else if (node->target->median == 1)
	{
		while (node->target->push_cost != 0)
		{
			rotate_stack(a,1); // ehka vaarin
			node->target->push_cost -= 1;
		}
	}
	if (node->median == 0)
	{
		while (node->push_cost != 0)
		{
			reverse_stack(b,2);
			node->push_cost -= 1;
		}
	}
	if (node->median == 1)
	{
		while (node->push_cost != 0)
		{
			rotate_stack(b,2);
			node->push_cost -= 1;
		}
	}

	push_stack(b, a, 2);
	if ((*a)->num > (*a)->next->num)
	{
		//ft_printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
		rotate_stack(a,1);
	}
}

t_stack *find_min_num_node(t_stack *stack)
{
	t_stack *biggest_node;
	
	biggest_node = stack;
	//biggest_node = NULL;	
	//biggest_node->num = -2147483648;
	//ft_printf("Starting to find the min boy\n");
	while (stack)
	{
		if (stack->num < biggest_node->num)
		{
			biggest_node = stack;
		}
		stack = stack->next;
	}
	//ft_printf("found the min boy\n");	
	return (biggest_node);
}

void	find_target_b(t_stack *b, t_stack *a)
{
	t_stack *temp_a;
	t_stack *temp_target;
	long target;
	
	while (b)
	{
		target = LONG_MAX;
		temp_a = a;
		while (temp_a)
		{
			if ((temp_a->num > b->num) && temp_a->num < target)
			{
				target = temp_a->num;
				temp_target = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (target == LONG_MAX)
			b->target = find_min_num_node(a); // CHANGE TO MIN NOTE
		else
			b->target = temp_target;
		b = b->next;
		//ft_printf("bbbbbbbbbb\n");
	}
	//ft_printf("BBBBBBBBB\n");
}

void solver_call_a(t_stack **a, t_stack **b)
{
	//calculate position and median here
	// not modified
	calculate_median(*a);
	calculate_median(*b);
	calculate_position(*a);
	calculate_position(*b);

	// find taget nodes
	find_target_b(*b,*a); //needs modification
	
	//calculate cost
	calculate_cost_one(*b);
	calculate_cost_b(*a);
	calculate_cost_combined(*b);
	
	/*t_stack *print_node;
	
	print_node = (*b);
	ft_printf("cost calcualtions\n");
	while (print_node != NULL)
	{
		ft_printf("%d ", print_node->cheap);
		print_node = print_node->next;
	}
	ft_printf("\n");*/
	

	//push
	
	push_cheap_b(a,b);
	//print_list(a,b);
}
