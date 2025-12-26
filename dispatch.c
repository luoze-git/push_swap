/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:59:30 by luozguo           #+#    #+#             */
/*   Updated: 2025/12/26 15:06:55 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dispatch_sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size <= 1)
		return ;
	sort_big_radix(a, b);
	return ;
}

int	is_sorted(t_stack *a)
{
	t_node	*cur;

	if (a->size < 2)
		return (1);
	cur = a->top;  
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);  
		cur = cur->next; 
	}
	return (1); 
}
