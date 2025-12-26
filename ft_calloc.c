/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:59:36 by luozguo           #+#    #+#             */
/*   Updated: 2025/12/26 15:09:06 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// continuously allocate memory and set them to bytes of zero
// how to detect overflow : use an unequality as condition constraint
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	buffer;

	ptr = NULL;
	buffer = 0;
	if (count && size && count > SIZE_MAX / size)
		return (NULL);
	buffer = count * size;
	ptr = malloc(buffer);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, buffer);
	return (ptr);
}
