/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:00:58 by luozguo           #+#    #+#             */
/*   Updated: 2025/12/26 18:19:44 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// parse:  free(int_list) , free what's there in it
long	ft_atolll(char *s, int *int_list)
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
			fatal_exit(NULL, NULL, int_list);
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

static int	parse_one_int_element(char *token, int *int_list, int *cnt_nb)
{
	long	v;

	if (!arg_is_valid_number(token))
		return (0);
	v = ft_atolll(token, int_list);
	if (v < INT_MIN || v > INT_MAX)
		return (0);
	if (has_duplicate(int_list, *cnt_nb, (int)v))
		return (0);
	if (*cnt_nb >= 1000)
		return (0);
	int_list[(*cnt_nb)++] = (int)v;
	return (1);
}

static void	parsing_fatal(char **split, int *int_list)
{
	ft_free_split(split);
	fatal_exit(NULL, NULL, int_list);
}

static void	parse_argv_element(char *arg, int *int_list, int *cnt_nb)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split || !split[0])
		parsing_fatal(split, int_list);
	j = 0;
	while (split[j])
	{
		if (!parse_one_int_element(split[j], int_list, cnt_nb))
			parsing_fatal(split, int_list);
		j++;
	}
	ft_free_split(split);
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
		fatal_exit(NULL, NULL, NULL);
	cnt_nb = 0;
	i = 1;
	while (i < argc)
	{
		parse_argv_element(argv[i], int_list, &cnt_nb);
		i++;
	}
	*out_nb_count = cnt_nb;
	return (int_list);
}
