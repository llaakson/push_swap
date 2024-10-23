/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:18:25 by llaakson          #+#    #+#             */
/*   Updated: 2024/10/21 19:07:42 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(*(array + i));
		i++;
	}
	free(array);
}

void free_list(t_stack **stack)
{
	t_stack  *temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}	
}
int is_duplicate(char **array)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (array[i] != NULL)
	{
		while (j < i)
		{
			if (ft_atoi(array[i]) == ft_atoi(array[j]))
			{	
				//ft_printf("duplication found\n");
				return (0);
			}
			j++;
			//ft_printf("checking array\n");
		}
		i++;
		j = 0;
	}
	return (1);
}
int	is_sorted(t_stack *a)
{
	t_stack *sort;
	
	sort = a;
	while (sort->next != NULL)
	{
		if (sort->num > sort->next->num)
			return (0);
		sort = sort->next;
	}
	return (1);
}

int lstsize(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
