/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:42:33 by llaakson          #+#    #+#             */
/*   Updated: 2024/10/23 19:37:32 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_stack(t_stack **stack, int check)
{
	t_stack *last;
	
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
