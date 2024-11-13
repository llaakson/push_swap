/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:28:55 by llaakson          #+#    #+#             */
/*   Updated: 2024/11/07 19:59:06 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max_num_node(t_stack *stack)
{
	t_stack	*biggest_node;

	biggest_node = stack;
	while (stack)
	{
		if (stack->num > biggest_node->num)
		{
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

t_stack	*find_push_target(t_stack *stack)
{
	t_stack	*biggest_node;

	biggest_node = stack;
	while (stack)
	{
		if (stack->cheap == 1)
		{
			biggest_node = stack;
			break ;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

void	free_array(char **array, int argc)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	if (argc == 2)
	{
		while (array[i])
		{
			free(*(array + i));
			i++;
		}
		free(array);
	}
}

void	free_list(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	stack_error(t_stack **a, char **array, int argc)
{
	write(2, "Error\n", 6);
	free_list(a);
	free_array(array, argc);
	exit (1);
}
