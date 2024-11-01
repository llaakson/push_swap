/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:18:25 by llaakson          #+#    #+#             */
/*   Updated: 2024/11/01 18:25:38 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	if (*str == '-' || *str == '+' )
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + *str++ - 48;
	return (result * sign);
}

int	is_duplicate(char **array)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (array[i] != NULL)
	{
		while (j < i)
		{
			if (ft_atoi(array[i]) == ft_atoi(array[j]))
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	is_sorted(t_stack *a)
{
	t_stack	*sort;

	sort = a;
	while (sort->next != NULL)
	{
		if (sort->num > sort->next->num)
			return (0);
		sort = sort->next;
	}
	return (1);
}

int	lstsize(t_stack	*stack)
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
