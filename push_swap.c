/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:23:51 by llaakson          #+#    #+#             */
/*   Updated: 2024/11/01 19:06:40 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (0);
	node->next = NULL;
	node->num = n;
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

int	ft_isnumber(int i, int argc, char **array)
{
		int j;

		j = 0;
		if (array[i][j] == '-' || array[i][j] == '+')
			j++;
		if (array[i][j] == '\0')
		{
			write(2, "EEror\n", 6);
			free_array(array,argc);
			return (0);
		}
		while (array[i][j] != '\0')
		{
			if (!(ft_isdigit(array[i][j])))
			{
				write(2, "EEror\n", 6);
				free_array(array,argc);
				return (0);
			}
			j++;
		}
		return (1);
}

void	make_stack(t_stack **a, char **array, int argc)
{
	long	n;
	int		i;

	i = 0;
	while (array[i])
	{
		if (!(ft_isnumber(i, argc, array)))
		{
			free_list(a);
			exit (1);
		}
		n = ft_atol(array[i]);
		if (n < INT_MIN || n > INT_MAX)
		{
			write(2, "EEror\n", 6);
			free_array(array, argc);
			free_list(a);
			exit (1);
		}
		if (!(make_node(a, (int)n)))
		{
			free_array(array, argc);
			free_list(a);
			exit (1);
		}	
		i++;
	}	
}

char	**make_array(int argc, char **argv)
{	
	char	**array;
	int		i;

	array = NULL;
	i = 0;
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
			exit(1);
		array = ft_split(argv[1], ' ');
		if (array == NULL)
			exit(1);
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
		return (0);
	if (argc >= 2)
		array = make_array(argc, argv);
	if (!(is_duplicate(array)))
	{
		write(2, "Error\n", 6);
		free_array(array, argc);
		return (1);
	}
	make_stack(&a, array, argc);
	if (!(is_sorted(a)))
		check_list_size(&a, &b);
	free_array(array, argc);
	free_list(&a);
	return (0);
}
