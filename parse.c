/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:00:58 by luozguo           #+#    #+#             */
/*   Updated: 2025/12/26 15:00:59 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (!s || s[0] == '\0')
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	set_stderr_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long	ft_atolll(char *s)
{
	long	res;
	int		sign;
	int		i;
	int		digit;

	res = 0;
	sign = 1;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		digit = s[i] - '0';
		if (res > (LONG_MAX - digit) / 10)
			set_stderr_exit();
		res = res * 10 + digit;
		i++;
	}
	return (res * sign);
}

int	has_duplicate(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}

static void	parse_one_int_element(char *token, int *int_list, int *cnt_nb)
{
	long	v;

	if (!arg_is_valid_number(token))
		set_stderr_exit();
	v = ft_atolll(token);
	if (v < INT_MIN || v > INT_MAX)
		set_stderr_exit();
	if (has_duplicate(int_list, *cnt_nb, (int)v))
		set_stderr_exit();
	int_list[(*cnt_nb)++] = (int)v;
}

// free a NULL terminated double pointer
void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// only allocate at most for 1000 int length of input
int	*parse_integer_input(int argc, char **argv, int *out_nb_count)
{
	int		*int_list;
	int		cnt_nb;
	int		i;
	char	**split;
	int		j;

	int_list = malloc(sizeof(int) * 1000);
	if (!int_list)
		set_stderr_exit();
	cnt_nb = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			set_stderr_exit();
		j = 0;
		while (split[j])
		{
			parse_one_int_element(split[j], int_list, &cnt_nb);
			j++;
		}
		ft_free_split(split);
		i++;
	}
	*out_nb_count = cnt_nb;
	return (int_list);
}
