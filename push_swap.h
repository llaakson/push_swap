/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:46:01 by llaakson          #+#    #+#             */
/*   Updated: 2024/08/27 16:13:16 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node {
	int	i;
	char **array_a;
	char **array_aa;
	int data;
	struct s_lst *temp;
	struct s_list *next;
	struct s_list *prev;
} t_node;

int	main(int argc, char	**argv);

#endif
