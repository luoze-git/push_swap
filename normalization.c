/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:01:03 by luozguo           #+#    #+#             */
/*   Updated: 2025/12/26 16:16:30 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// naive selection sort - compare each to all the others
static void	sort_int_array(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	find_index(int *sorted, int n, int value)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	normalize_values(int *int_list, int nint)
{
	int	*sorted;
	int	i;

	sorted = malloc(sizeof(int) * nint);
	if (!sorted)
		set_stderr_exit();
	i = 0;
	while (i < nint)
	{
		sorted[i] = int_list[i];
		i++;
	}
	sort_int_array(sorted, nint);
	i = 0;
	while (i < nint)
	{
		int_list[i] = find_index(sorted, nint, int_list[i]);
		i++;
	}
	free(sorted);
}
