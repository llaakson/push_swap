/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:56:19 by llaakson          #+#    #+#             */
/*   Updated: 2024/10/24 21:55:56 by llaakson         ###   ########.fr       */
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
		//ft_printf("position %d number %d\n", stack->position, stack->num);
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

void	find_target(t_stack *b, t_stack *a)
{
	t_stack *temp_b;
	int target;
	
	//temp = b;
	target = 2147483647;
	while (a)
	{
		temp_b = b;
		while (temp_b)
		{	
			a->target = temp_b;
			//ft_printf("target node B: %p \n", a->target);
			temp_b = temp_b->next;
		}
		//ft_printf("You did it wee!!");
		a = a->next;
	}
	//ft_printf("COMPLITED\n");
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

void calculate_cost_combined(t_stack *a)
{
	while (a)
	{
		//ft_printf("%p   %p \n",a->target, a);
		ft_printf("%p   %d %d %d %d \n",a->target, a->push_cost,a->median, a->target->push_cost,a->target->median);
		a->push_cost = a->target->push_cost + a->push_cost; 
		//ft_printf("total %d \n", a->push_cost);
		a = a->next;
	}	
}

void push_cheap(t_stack **a, t_stack **b)
{
	if ((*a)->push_cost == 0)
	{
		push_stack(a, b, 1);
		//ft_printf("pushed a to b cost 0\n");
	}
	else
	{
		push_stack(a, b, 1);
		//ft_printf("pushed a to b cost over 0\n");
	}	
}
