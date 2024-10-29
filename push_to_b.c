/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:56:19 by llaakson          #+#    #+#             */
/*   Updated: 2024/10/29 18:39:53 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_position(t_stack *stack)
{
	int position;

	position = 0;	
	while (stack)
	{
		stack->position = position;
		position++;
		stack = stack->next;
	}
}

void	calculate_median(t_stack *stack)
{
	int median;
	int node_num;

	node_num = 0; // voi olla ongelman lahde
	median = lstsize(stack)/2;
	while (stack)
	{	
		if (median > node_num)
			stack->median = 1;
		else
			stack->median = 0;
		node_num++;
		stack = stack->next;
	}
		
}

t_stack *find_max_num_node(t_stack *stack)
{
	t_stack *biggest_node;
	
	biggest_node = stack;
	while (stack)
	{
		if (stack->num > biggest_node->num)
		{
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}
void	find_target(t_stack *b, t_stack *a)
{
	t_stack *temp_b;
	t_stack *temp_target;
	long target;
	
	while (a)
	{
		target = LONG_MIN;
		temp_b = b;
		while (temp_b)
		{
			if ((a->num > temp_b->num) && (temp_b->num > target))
			{	
				target = temp_b->num;
				temp_target = temp_b;		
			}
			temp_b = temp_b->next;
		}
		if (target == LONG_MIN)
			a->target = find_max_num_node(b);
		else
			a->target = temp_target;
		a = a->next;
	}
}

void calculate_cost_one(t_stack *a)
{
	int list_size;

	list_size = lstsize(a);
	while (a)
	{
		if (a->median == 1)
			a->push_cost = a->position; 

		if (a->median == 0)
			a->push_cost = (list_size - a->position); 
		a = a->next;
	}
}

void calculate_cost_b(t_stack *b)
{
	int list_size;

	list_size = lstsize(b);
	while (b)
	{
		if (b->median == 1)
			b->push_cost = b->position;

		if (b->median == 0)
			b->push_cost = (list_size - b->position); 
		b = b->next;
	}
}

void calculate_cost_combined(t_stack *a)
{
	long cheap;
	t_stack *temp_cheap;

	cheap = LONG_MAX;
	while (a)
	{	
		a->total = a->target->push_cost + a->push_cost; 
		if (a->total < cheap)
		{
			if (cheap != LONG_MAX)
				temp_cheap->cheap = 0;
			a->cheap = 1;
			cheap = a->total;
			temp_cheap = a;
		}
		a = a->next;
	}	
}

t_stack *find_push_target(t_stack *stack)
{
	t_stack *biggest_node;
	
	biggest_node = stack;
	while (stack)
	{
		if (stack->cheap == 1)
		{
			biggest_node = stack;
			break ;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

void push_cheap(t_stack **a, t_stack **b)
{
	t_stack *node;

	node = find_push_target(*a);
	if (node->target->median == 0)
	{
		while (node->target->push_cost != 0)
		{
			if (node->median == 0 && node->push_cost != 0)
			{
				reverse_stack(a,3);
				reverse_stack(b,3);
				node->target->push_cost -= 1;
				node->push_cost -= 1;
				write(1, "rrr\n", 4);
			}
			else
			{
				reverse_stack(b,2);
				node->target->push_cost -= 1;
			}
		}
	}
	else if (node->target->median == 1)
	{
		while (node->target->push_cost != 0)
		{
			if (node->median == 1 && node->push_cost != 0)
			{
				rotate_stack(a,3);
				rotate_stack(b,3);
				node->target->push_cost -= 1;
				node->push_cost -= 1;
				write(1, "rr\n", 3);
			}
			else
			{
				rotate_stack(b,2);
				node->target->push_cost -= 1;
			}
		}
	}
	if (node->median == 0)
	{
		while (node->push_cost != 0)
		{
			reverse_stack(a,1);
			node->push_cost -= 1;
		}
	}
	if (node->median == 1)
	{
		while (node->push_cost != 0)
		{
			rotate_stack(a,1);
			node->push_cost -= 1;
		}
	}
	node->cheap = 0; 
	push_stack(a, b, 1);
}
