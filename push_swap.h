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
void	sort_tab(t_node *pile, int size, int *tab);

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
int	*sort_pile(t_node *pile, int argc);
int		is_sort(t_node *pile_a);

int		calc_chunk_size(int total_size, int nb_chunks, int chunk_index);
void	init_chunk(t_chunk *chunk, int start, int size);
int	find_value(t_node *pile_a, t_chunk *chunk, int *tab);
void	log_pose(t_node **pile_a, int pos);
void log_pose_b(t_node **pile_b, int pos);
void init_chunks(t_chunk *chunks, int total_size, int nb_chunks);
int choose_chunk_count(int size);
void push_chunks_to_b(t_node **pile_a, t_node **pile_b, t_chunk *chunks, int nb_chunks, int *tab);
void return_to_a(t_node **pile_a, t_node **pile_b);
int find_max_position(t_node *pile);
void chunk_sort(t_node **pile_a, t_node **pile_b);

#endif
