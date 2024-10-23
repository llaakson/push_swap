/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:25:55 by llaakson          #+#    #+#             */
/*   Updated: 2024/10/22 18:51:49 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **stack)

{
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void sa(t_stack **a)
{
	swap_stack(a);
	write(1, "sa\n", 3);
}

void sb(t_stack **b)
{
	swap_stack(b);
	write(1, "sb\n", 3);
}

void ss(t_stack **a, t_stack **b)
{
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 3);
}
	
