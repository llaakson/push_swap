/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:43:13 by llaakson          #+#    #+#             */
/*   Updated: 2024/08/24 20:59:44 by llaakson         ###   ########.fr       */
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

int	main(int argc, char		**argv)
{
	t_node push;
	
	if (!check_arguments(argc, argv, &push))
	{	
		ft_printf("no arguments\n");
		exit (0);
	}
	ft_printf("All argmuents are numbers ! main\n");
	ft_printf("libft working argc %d\n", argc);
	return (0);
}
