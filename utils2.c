/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:21:29 by saibelab          #+#    #+#             */
/*   Updated: 2025/07/08 16:48:55 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_node **pile_a, int s)
{
	t_node *last;
	t_node *first;

	if(!pile_a || node_size(*pile_a) < 2)
		return ;

	last = node_last(*pile_a);
	first = *pile_a;

	*pile_a = first->next;
	first->next = NULL;
	last->next = first;
	if (!s)
		ft_printf("ra\n");
}

void rb(t_node **pile_b, int s)
{
	t_node *last;
	t_node *first;

	if(!pile_b || node_size(*pile_b) < 2)
		return ;

	last = node_last(*pile_b);
	first = *pile_b;

	*pile_b = first->next;
	first->next = NULL;
	last->next = first;
	if (!s)
		ft_printf("rb\n");
}

void rr(t_node **pile_a, t_node **pile_b)
{
	ra(pile_a, 1);
	rb(pile_b, 1);
	printf("rr\n");
}

void rrb(t_node **pile_b, int s)
{
	t_node *last;
	t_node *prev;

	if(!pile_b || node_size(*pile_b) < 2)
		return ;

	last = node_last(*pile_b);
	prev = NULL;

	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *pile_b;
	*pile_b = last;
	if (!s)
		ft_printf("rrb\n");
}

void rra(t_node **pile_a, int s)
{
	t_node *last;
	t_node *prev;

	if(!pile_a || node_size(*pile_a) < 2)
		return ;

	last = node_last(*pile_a);
	prev = NULL;

	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *pile_a;
	*pile_a = last;
	if (!s)
		ft_printf("rra\n");
}

void rrr(t_node **pile_a, t_node **pile_b)
{
	rra(pile_a, 1);
	rrb(pile_b, 1);
	printf("rrr\n");
}
