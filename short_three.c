/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:20:11 by llaakson          #+#    #+#             */
/*   Updated: 2024/10/24 13:22:00 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_three(t_stack **a)
{
	int first;
	int second;
	int third;

	first = (*a)->num;
	second = (*a)->next->num;
	third = (*a)->next->next->num;
	if((first > second) && (first < third) && (second < third))
		sa(a);
	else if((first > second) && (first > third) && (second > third))
	{
		sa(a);
		reverse_stack(a);
	}
	else if((first > second) && (first > third) && (second < third))
		rotate_stack(a,1);	
	else if((first < second) && (first < third) && (second > third))
	{
		sa(a);
		rotate_stack(a,1);
	}	
	else if((first < second) && (first > third) && (second > third))
		reverse_stack(a);	
			
}
