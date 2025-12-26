/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:00:24 by luozguo           #+#    #+#             */
/*   Updated: 2025/12/26 18:04:32 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// free(int_list) , free(stack created)
void stack_init(t_stack *s, char name)
{
	s->top = NULL;
	s->size = 0;
	s->name = name;
}

// create a new node with a given value
t_node *node_new(int value)
{
	t_node *n;

	n = malloc(sizeof(t_node));
	if (!n)
		return NULL;
	n->value = value;
	n->next = NULL;
	return (n);
}

void stack_builder(t_stack *stack, int *int_list, int nint, char name)
{
	int i;
	t_node *prev;
	t_node *new;

	stack_init(stack, name);
	i = 0;
	prev = NULL;
	while (i < nint)
	{
		new = node_new(int_list[i]);
		if (!new)
			pre_exit_stack(stack , int_list);
		if (!prev)
			stack->top = new;
		else
			prev->next = new;
		prev = new;
		stack->size++;
		i++;
	}
}

void pre_exit_stack(t_stack *s , int* int_list)
{
	free_stack(s);
	free(int_list);
	set_stderr_exit();
}

// stop when null detected
void free_stack(t_stack *s)
{
	t_node *tmp;
	
	if (!s)
		return;
	while (s->top)
	{
		tmp = s->top->next;
		free(s->top);
		s->top = tmp;
	}
}

int is_stack_sorted(t_stack *s)
{
	t_node *cur;

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
