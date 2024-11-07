/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:41:08 by llaakson          #+#    #+#             */
/*   Updated: 2024/11/07 16:17:55 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_cheap_a(t_stack **a, t_stack **b, t_stack *node)
{
	if (node->median == 0)
	{
		while (node->push_cost != 0)
		{
			reverse_stack(b, 2);
			node->push_cost -= 1;
		}
	}
	if (node->median == 1)
	{
		while (node->push_cost != 0)
		{
			rotate_stack(b, 2);
			node->push_cost -= 1;
		}
	}
	push_stack(b, a, 2);
}

static void	check_rotation_a(t_stack **a, t_stack **b, t_stack *node)
{
	if (node->target->median == 1)
	{
		while (node->target->push_cost != 0)
		{
			if (node->median == 1 && node->push_cost != 0)
			{
				rotate_stack(b, 3);
				rotate_stack(a, 3);
				node->target->push_cost -= 1;
				node->push_cost -= 1;
				write(1, "rr\n", 3);
			}
			else
			{
				rotate_stack(a, 1);
				node->target->push_cost -= 1;
			}
		}
	}
	push_cheap_a(a, b, node);
}

void	check_reverse_a(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = find_push_target(*b);
	if (node->target->median == 0)
	{
		while (node->target->push_cost != 0)
		{
			if (node->median == 0 && node->push_cost != 0)
			{
				reverse_stack(b, 3);
				reverse_stack(a, 3);
				node->target->push_cost -= 1;
				node->push_cost -= 1;
				write(1, "rrr\n", 4);
			}
			else
			{
				reverse_stack(a, 1);
				node->target->push_cost -= 1;
			}
		}
	}
	check_rotation_a(a, b, node);
}

t_stack	*find_min_num_node(t_stack *stack)
{
	t_stack	*biggest_node;

	biggest_node = stack;
	while (stack)
	{
		if (stack->num < biggest_node->num)
		{
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

void	find_target_b(t_stack *b, t_stack *a)
{
	t_stack	*temp_a;
	t_stack	*temp_target;
	long	target;

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
			b->target = find_min_num_node(a);
		else
			b->target = temp_target;
		b = b->next;
	}
}
