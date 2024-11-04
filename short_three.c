/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:20:11 by llaakson          #+#    #+#             */
/*   Updated: 2024/11/04 14:40:28 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->num;
	second = (*a)->next->num;
	third = (*a)->next->next->num;
	if ((first > second) && (first < third) && (second < third))
		swap_stack(a, 1);
	else if ((first > second) && (first > third) && (second > third))
	{
		swap_stack(a, 1);
		reverse_stack(a, 1);
	}
	else if ((first > second) && (first > third) && (second < third))
		rotate_stack(a, 1);
	else if ((first < second) && (first < third) && (second > third))
	{
		swap_stack(a, 1);
		rotate_stack(a, 1);
	}
	else if ((first < second) && (first > third) && (second > third))
		reverse_stack(a, 1);
}

void	solver_call_a(t_stack **a, t_stack **b)
{
	calculate_median(*a);
	calculate_median(*b);
	calculate_position(*a);
	calculate_position(*b);
	find_target_b(*b,*a);
	calculate_cost_one(*b);
	calculate_cost_b(*a);
	calculate_cost_combined(*b);
	check_reverse_a(a, b);
}

void	solver_call(t_stack **a, t_stack **b)
{
	calculate_median(*a);
	calculate_median(*b);
	calculate_position(*a);
	calculate_position(*b);
	find_target(*b,*a);
	calculate_cost_one(*a);
	calculate_cost_b(*b);
	calculate_cost_combined(*a);
	check_reverse_b(a, b);
}

void	solve_over_three(t_stack **a, t_stack **b)
{
	t_stack	*final;

	while (lstsize(*a) != 3 && lstsize(*b) < 2)
		push_stack(a, b, 1);
	while (lstsize(*a) != 3)
		solver_call(a, b);
	short_three(a);
	while (lstsize(*b) != 0)
		solver_call_a(a, b);
	final = find_min_num_node(*a);
	calculate_median(final);
	while ((*a)->num > final->num)
	{
		if (final->median == 1)
			rotate_stack(a, 1);
		else if (final->median == 0)
			reverse_stack(a, 1);
	}
}

void	check_list_size(t_stack **stack, t_stack **b)
{
	int	size;

	size = lstsize(*stack);
	if (size == 2)
		swap_stack(stack, 1);
	if (size == 3)
		short_three(stack);
	if (size > 3)
		solve_over_three(stack, b);
}
