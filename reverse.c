/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:24:36 by llaakson          #+#    #+#             */
/*   Updated: 2024/10/23 13:30:18 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_stack(t_stack **stack)
{
	t_stack *last;

	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	write(1, "rra\n", 4);

}
	
	
	
