/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:18:55 by llaakson          #+#    #+#             */
/*   Updated: 2024/10/23 21:04:55 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_stack(t_stack **a, t_stack **b, int s)
{
	t_stack *temp;
	//t_stack *last_temp;

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
	if (s == 1)
		write(1, "pb\n", 3);
	if (s == 2)
		write(1, "pa\n", 3);
}
