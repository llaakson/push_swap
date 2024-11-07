/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:58:54 by llaakson          #+#    #+#             */
/*   Updated: 2024/11/07 15:57:09 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_cheap_b(t_stack **a, t_stack **b, t_stack *node)
{
	if (node->median == 0)
	{
		while (node->push_cost != 0)
		{
			reverse_stack(a, 1);
			node->push_cost -= 1;
		}
	}
	if (node->median == 1)
	{
		while (node->push_cost != 0)
		{
			rotate_stack(a, 1);
			node->push_cost -= 1;
		}
	}
	node->cheap = 0;
	push_stack(a, b, 1);
}

static void	check_rotation_b(t_stack **a, t_stack **b, t_stack *node)
{
	if (node->target->median == 1)
	{
		while (node->target->push_cost != 0)
		{
			if (node->median == 1 && node->push_cost != 0)
			{
				rotate_stack(a, 3);
				rotate_stack(b, 3);
				node->target->push_cost -= 1;
				node->push_cost -= 1;
				write(1, "rr\n", 3);
			}
			else
			{
				rotate_stack(b, 2);
				node->target->push_cost -= 1;
			}
		}
	}
	push_cheap_b(a, b, node);
}

void	check_reverse_b(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = find_push_target(*a);
	if (node->target->median == 0)
	{
		while (node->target->push_cost != 0)
		{
			if (node->median == 0 && node->push_cost != 0)
			{
				reverse_stack(a, 3);
				reverse_stack(b, 3);
				node->target->push_cost -= 1;
				node->push_cost -= 1;
				write(1, "rrr\n", 4);
			}
			else
			{
				reverse_stack(b, 2);
				node->target->push_cost -= 1;
			}
		}
	}
	check_rotation_b(a, b, node);
}

void	find_target(t_stack *b, t_stack *a)
{
	t_stack	*temp_b;
	t_stack	*temp_target;
	long	target;

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
