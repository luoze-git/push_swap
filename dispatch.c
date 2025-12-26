/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:59:30 by luozguo           #+#    #+#             */
/*   Updated: 2025/12/26 16:27:54 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dispatch_sort(t_stack *a, t_stack *b)
{
	if (is_stack_sorted(a))
		return ;
	if (a->size <= 1)
		return ;
	sort_big_radix(a, b);
	return ;
}

