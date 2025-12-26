/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:18:14 by luozguo           #+#    #+#             */
/*   Updated: 2025/12/26 15:18:26 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// put a given node to the top of a stack
// mini-step 1/2 for ops
void	stack_push(t_stack *s, t_node *n)
{
	n->next = s->top;
	s->top = n;
	s->size++;
}

// pop a node from a stack
// mini-step 2/2 for ops
t_node	*stack_pop(t_stack *s)
{
	t_node	*n;

	if (s->size == 0)
		return (NULL);
	n = s->top;
	s->top = n->next;
	n->next = NULL;
	s->size--;
	return (n);
}
