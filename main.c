/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:01:07 by luozguo           #+#    #+#             */
/*   Updated: 2025/12/26 15:08:47 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int size;
	t_stack a;
	t_stack b;
	int *int_list;
	int_list = parse_integer_input(argc, argv, &size);
	normalize_values(int_list, size);
	stack_builder(&a, int_list, size, 'a');
	stack_builder(&b, NULL, 0, 'b');
	free(int_list);
	dispatch_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);

	return (0);
}