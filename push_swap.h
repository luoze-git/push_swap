/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:00:46 by luozguo           #+#    #+#             */
/*   Updated: 2025/12/26 16:28:08 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int value;
	struct s_node *next;
} t_node;

typedef struct s_stack
{
	t_node *top;
	int size;
	char name;
} t_stack;

void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);

void dispatch_sort(t_stack *a, t_stack *b);

void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);

void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);

void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);

void stack_init(t_stack *s, char name);
t_node *node_new(int value);
void stack_push(t_stack *s, t_node *n);
t_node *stack_pop(t_stack *s);
void free_stack(t_stack *s);

int is_stack_sorted(t_stack *s);

void stack_builder(t_stack *stack, int *int_list, int nint,
				   char name);
void normalize_values(int *int_list, int nint);
void sort_big_radix(t_stack *a, t_stack *b);

int arg_is_valid_number(char *s);
void set_stderr_exit(void);
long ft_atolll(char *s);
int has_duplicate(int *arr, int size, int value);
int *parse_integer_input(int argc, char **argv,
						 int *out_nb_count);

/*libft functions*/
void ft_bzero(void *s, size_t n);
void *ft_calloc(size_t count, size_t size);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strdup(const char *s);
size_t ft_strlen(const char *s);
void ft_free_split(char **ptr);
char **ft_split(char const *s, char c);

#endif
