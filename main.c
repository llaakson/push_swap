/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:43:13 by llaakson          #+#    #+#             */
/*   Updated: 2024/08/27 17:29:52 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_string(char *argv)
{
	while (*argv)
	{
		if (*argv == ' ')
			argv++;
		if (*argv == '-' || *argv == '+')
			argv++;
		if (!(*argv >= '0' && *argv <= '9'))
		{
			ft_printf("argument is not a valid number\n");
			exit (0);
		}
		argv++;
	}
	return (1);	
}

int	check_multi_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argc > 1)
	{
		if (!check_string(argv[i]))
			return (0);
		i++;
		argc--;
	}	
	return (1);
}
		
int	check_arguments(int argc, char **argv, t_node *push)
{
	int r;
	
	r = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		r = check_string(argv[1]);
		if (r == 1)
			push->array_a = ft_split(argv[1], ' ');
	}
	if (argc > 2)
	{
		r = check_multi_arguments(argc, argv);
		//if (r == 1)
		//	convert_array(argc, argv, push);
	}
	return (r);
}

/*struct node* create_node(int data)
{
	t_node *new;

	new = malloc(sizeof(struct t_node));
	new->data = data;
	new->next = NULL;
	return (*new);
}*/

void	make_stack(t_list *push, int a)
{
	struct node* new_node;
	//t_node *last_node;
	
	new_node = create_node(a);
	
	push->next = node;
	node->prev = push; 	
}

int	main(int argc, char		**argv)
{
	t_node *a;
	//t_node *b;
	
	if (!check_arguments(argc, argv, &a))
	{	
		ft_printf("no arguments\n");
		exit (0);
	}
	ft_printf("All argmuents are numbers ! main\n");
	ft_printf("libft working argc %d\n", argc);
	make_stack(&a, argv[1]);
	ft_printf("Node :%d", a->next);
	
	return (0);
}
