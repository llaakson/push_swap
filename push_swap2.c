/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:23:51 by llaakson          #+#    #+#             */
/*   Updated: 2024/10/23 21:30:28 by llaakson         ###   ########.fr       */
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
void check_stack_b_mins(t_stack **b)
{
	int min;
	int max;

	max = (*b)->num;
	if (max > (*b)->next->num)
		min = (*b)->next->num;
	else
	{
		max = (*b)->next->num;
		min = (*b)->num;
	}
	ft_printf("min %d max %d\n", min, max); 
	if ((*b)->num == min)
		rotate_stack(b,2); // no rb yet?
}

void solve_over_three(t_stack **a, t_stack **b)
{
	// blindly push first two b stack
	push_stack(a, b, 1);
	push_stack(a, b, 1);
	//push_stack(a, b, 1);
	// calculated cheapest push to b stack
	
	check_stack_b_mins(b);
 	
		
	//while (lstsize(*a) > 3)
	//	push_stack(a, b, 1);
	
	
	/*short_three(a);
	while (lstsize(*b) != 0)
		push_stack(b, a, 2);*/
}
void	make_node(t_stack **stack, int n)
{
	t_stack *node;
	t_stack *last_node;

	node = malloc(sizeof(t_stack));
	if (!(node))
		return ;
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
}

void	make_stack(t_stack **a, char **array)
{
	int n; 
	int i;

	i = 0;
	while (array[i])
	{
		n = ft_atoi(array[i]);
		make_node(a, n);
		i++;
	}
	
}

void print_list(t_stack **stack, t_stack **b)
{
	t_stack *print_node;
	t_stack *print_b;
	
	print_node = (*stack);
	ft_printf("stack a: ");
	while (print_node != NULL)
	{
		ft_printf("%d ", print_node->num);
		print_node = print_node->next;
	}
	ft_printf("\n");
	print_b = (*b);
	ft_printf("stack b: ");
	while (print_b != NULL)
	{
		ft_printf("%d ", print_b->num);
		print_b = print_b->next;
	}
	ft_printf("\n");	
}

void	check_list_size(t_stack **stack, t_stack **b)
{
	int size;

	size = lstsize(*stack);
	//ft_printf("%d ", size);
	if (size == 2)
		sa(stack);
	if (size == 3)
		short_three(stack);
	if (size > 3)
		solve_over_three(stack, b);
}

char **make_array(int argc, char **argv)
{	
	char **array;
	int i;

	array = NULL;
	i = 0;
	if (argc == 2)
	{
		array = ft_split(argv[1],' ');
		return (array);
	}
	else
		array = (argv+1); // malloc this
	return (array);
	
}
int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	char **array;

	a = NULL;
	b = NULL;
	array = NULL;
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc >= 2)
		array = make_array(argc, argv);
		//array = ft_split(argv[1],' ');
	if (!(is_duplicate(array)))
	{
		write(1,"DUP\n",4);
		return (1);
	}
	make_stack(&a, array);
	if (!(is_sorted(a)))
	{
		check_list_size(&a, &b);
	}
	print_list(&a, &b);
	//free_array(array);
	free_list(&a);

	return (0);
}
