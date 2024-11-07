/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:23:51 by llaakson          #+#    #+#             */
/*   Updated: 2024/11/07 19:32:59 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	make_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (0);
	node->next = NULL;
	node->num = n;
	if (!(is_duplicate(*stack, node)))
	{
		free(node);
		return (0);
	}
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	return (1);
}

static int	ft_isnumber(int i, char **array)
{
	int	j;

	j = 0;
	if (array[i][j] == '-' || array[i][j] == '+')
		j++;
	if (array[i][j] == '\0')
		return (0);
	while (array[i][j] != '\0')
	{
		if (!(ft_isdigit(array[i][j])))
			return (0);
		j++;
	}
	return (1);
}

static void	make_stack(t_stack **a, char **array, int argc)
{
	long	n;
	int		i;

	i = 0;
	while (array[i])
	{
		if (!(ft_isnumber(i, array)))
			stack_error(a, array, argc);
		n = ft_long_atoi(array[i]);
		if (n < INT_MIN || n > INT_MAX)
			stack_error(a, array, argc);
		if (!(make_node(a, (int)n)))
			stack_error(a, array, argc);
		i++;
	}	
}

static char	**make_array(int argc, char **argv)
{	
	char	**array;
	int		i;

	array = NULL;
	i = 0;
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		array = ft_split(argv[1], ' ');
		if (array == NULL)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		return (array);
	}
	else
		array = (argv + 1);
	return (array);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**array;

	a = NULL;
	b = NULL;
	array = NULL;
	if (argc < 2)
		return (1);
	if (argc >= 2)
		array = make_array(argc, argv);
	if (array == NULL || array[0] == NULL)
		stack_error(&a, array, argc);
	make_stack(&a, array, argc);
	if (!(is_sorted(a)))
		check_list_size(&a, &b);
	free_array(array, argc);
	free_list(&a);
	return (0);
}
