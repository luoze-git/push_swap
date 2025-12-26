/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:00:24 by luozguo           #+#    #+#             */
/*   Updated: 2025/12/26 15:18:44 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *s, char name)
{
	s->top = NULL;
	s->size = 0;
	s->name = name;
}

// create a new node with a given value
t_node	*node_new(int value)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		set_stderr_exit();
	n->value = value;
	n->next = NULL;
	return (n);
}

void	stack_builder(t_stack *stack, int *int_list, int nint, char name)
{
	int		i;
	t_node	*cur;

	stack_init(stack, name);
	i = 0;
	if (nint == 0)
		return ;
	stack->top = node_new(int_list[i]);
	cur = stack->top;
	stack->size++;
	i++;
	while (i < nint)
	{
		cur->next = node_new(int_list[i]);
		cur = cur->next;
		stack->size++;
		i++;
	}
	return ;
}

void	free_stack(t_stack *s)
{
	t_node	*tmp;

	while (s->top)
	{
		tmp = s->top->next;
		free(s->top);
		s->top = tmp;
	}
}

int	is_stack_sorted(t_stack *s)
{
	t_node	*cur;

	if (s->size <= 1)
		return (1);
	cur = s->top;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}
