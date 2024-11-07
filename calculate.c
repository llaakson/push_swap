/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:42:47 by llaakson          #+#    #+#             */
/*   Updated: 2024/11/06 16:17:51 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_position(t_stack *stack)
{
	int	position;

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
	int	median;
	int	node_num;

	node_num = 0;
	median = lstsize(stack) / 2;
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

void	calculate_cost_one(t_stack *a)
{
	int	list_size;

	list_size = lstsize(a);
	while (a)
	{
		if (a->median == 1)
			a->push_cost = a->position;
		if (a->median == 0)
			a->push_cost = (list_size - a->position);
		a->cheap = 0;
		a = a->next;
	}
}

void	calculate_cost_b(t_stack *b)
{
	int	list_size;

	list_size = lstsize(b);
	while (b)
	{
		if (b->median == 1)
			b->push_cost = b->position;
		if (b->median == 0)
			b->push_cost = (list_size - b->position);
		b->cheap = 0;
		b = b->next;
	}
}

void	calculate_cost_combined(t_stack *a)
{
	long	check;
	t_stack	*temp_cheap;

	check = LONG_MAX;
	while (a)
	{	
		a->total = a->target->push_cost + a->push_cost;
		if (a->target->median == a->median)
		{
			while ((a->total > a->target->push_cost)
				&& (a->total > a->push_cost))
				a->total -= 1;
		}
		if (a->total < check)
		{
			if (check != LONG_MAX)
				temp_cheap->cheap = 0;
			a->cheap = 1;
			check = a->total;
			temp_cheap = a;
		}
		a = a->next;
	}	
}
