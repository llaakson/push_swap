void push_cheap(t_stack **a, t_stack **b)
{
	t_stack *node;

	node = find_push_target(*a);
	if (node->target->median == 0)
	{
		while (node->target->push_cost != 0)
		{
			if (node->median == 0 && node->push_cost != 0)
			{
				reverse_stack(a,3);
				reverse_stack(b,3);
				node->target->push_cost -= 1;
				node->push_cost -= 1;
				write(1, "rrr\n", 4);
			}
			else
			{
				reverse_stack(b,2);
				node->target->push_cost -= 1;
			}
		}
	}
	else if (node->target->median == 1)
	{
			if (node->median == 1 && node->push_cost != 0)
			{
				rotate_stack(a,3);
				rotate_stack(b,3);
				node->target->push_cost -= 1;
				node->push_cost -= 1;
				write(1, "rr\n", 3);
			}
			else
			{
				rotate_stack(b,2);
				node->target->push_cost -= 1;
			}
	}
	if (node->median == 0)
	{
		while (node->push_cost != 0)
		{
			reverse_stack(a,1);
			node->push_cost -= 1;
		}
	}
	if (node->median == 1)
	{
		while (node->push_cost != 0)
		{
			rotate_stack(a,1);
			node->push_cost -= 1;
		}
	}
 
	push_stack(a, b, 1);
}

void push_cheap(t_stack **a, t_stack **b)
{
	t_stack *node;

	node = find_push_target(*a);
	
	if (node->target->median == 0)
	{
		while (node->target->push_cost != 0)
		{
			reverse_stack(b,2);
			node->target->push_cost -= 1;
		}
	}
	else if (node->target->median == 1)
	{
		while (node->target->push_cost != 0)
		{
			rotate_stack(b,2); // ehka vaarin
			node->target->push_cost -= 1;
		}
	}
	if (node->median == 0)
	{
		while (node->push_cost != 0)
		{
			reverse_stack(a,1);
			node->push_cost -= 1;
		}
	}
	if (node->median == 1)
	{
		while (node->push_cost != 0)
		{
			rotate_stack(a,1);
			node->push_cost -= 1;
		}
	}
 
	push_stack(a, b, 1);

	/*if ((*a)->push_cost == 0)
	{
		push_stack(a, b, 1);
		//ft_printf("pushed a to b cost 0\n");
	}
	else
	{
		push_stack(a, b, 1);
		//ft_printf("pushed a to b cost over 0\n");
	}*/	
}

