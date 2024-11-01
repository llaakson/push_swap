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

