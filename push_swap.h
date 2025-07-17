/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:41:02 by saibelab          #+#    #+#             */
/*   Updated: 2025/07/11 15:28:38 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_node {
	int value;
	struct s_node *next;
}	t_node;

typedef struct s_chunk
{
	int start;
	int end;
} t_chunk;

void	pa(t_node **pile_a, t_node **pile_b);
void	pb(t_node **pile_a, t_node **pile_b);
void	rrr(t_node **pile_a, t_node **pile_b);
void	rra(t_node **pile_a, int s);
void	rrb(t_node **pile_b, int s);
void	rr(t_node **pile_a, t_node **pile_b);
void	ra(t_node **pile_a, int s);
void	rb(t_node **pile_b, int s);
void	sa(t_node **pile_a, int s);
void	sb(t_node **pile_b, int s);
void	ss(t_node **pile_a, t_node **pile_b);

void	init_args(int argc, char **argv, t_node **pile);

int		is_valid(char *arg);
int		invalid_char (char **args);
int		check_double(char **argv);
int		is_overflow(char **args);
int		check_error(char **args);

t_node	*node_new(int value);
t_node	*node_last(t_node *lst);
void	node_add_back(t_node **lst, t_node *new);
int		node_size(t_node *lst);
void	free_pile(t_node *pile);

void 	sort_three(t_node **pile_a);
int		find_min_pos(t_node *pile);
void	sort_four(t_node **pile_a, t_node **pile_b);
void	sort_pile(t_node *pile, int argc);
int		is_sort(t_node *pile_a);

#endif
