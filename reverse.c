/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:24:36 by llaakson          #+#    #+#             */
/*   Updated: 2024/11/01 13:36:20 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_stack(t_stack **stack, int check)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
	if (check == 1)
		write(1, "rra\n", 4);
	if (check == 2)
		write(1, "rrb\n", 4);
}

void	rotate_stack(t_stack **stack, int check)
{
	t_stack	*last;

	last = find_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
	if (check == 1)
		write(1, "ra\n", 3);
	if (check == 2)
		write(1, "rb\n", 3);
}

void	swap_stack(t_stack **stack, int check)

{
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
	if (check == 1)
		write(1, "sa\n", 3);
	if (check == 2)
		write(1, "sb\n", 3);
}

void	push_stack(t_stack **a, t_stack **b, int check)
{
	t_stack	*temp;

	temp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	if (!(*b))
	{
		*b = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *b;
		temp->next->prev = temp;
		*b = temp;
	}
	if (check == 1)
		write(1, "pb\n", 3);
	if (check == 2)
		write(1, "pa\n", 3);
}	
