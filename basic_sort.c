/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:21:40 by saibelab          #+#    #+#             */
/*   Updated: 2025/07/11 13:13:46 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_node **pile_a)
{
	int a;
	int b;
	int c;

	if (!pile_a || !*pile_a || !(*pile_a)->next || !(*pile_a)->next->next)
		return;
	a = (*pile_a)->value;
	b = (*pile_a)->next->value;
	c = (*pile_a)->next->next->value;
	if (a > b && b < c && a < c)
		sa(pile_a, 0);
	else if (a > b && b > c)
	{
		sa(pile_a, 0);
		rra(pile_a, 0);
	}
	else if (a > b && b < c && a > c)
		ra(pile_a, 0);
	else if (a < b && b > c && a < c)
	{
		sa(pile_a, 0);
		ra(pile_a, 0);
	}
	else if (a < b && b > c && a > c)
		rra(pile_a, 0);
}

int find_min_pos(t_node *pile)
{
	int min = pile->value;
	int pos = 0;
	int i = 0;

	while (pile)
	{
		if (pile->value < min)
		{
			min = pile->value;
			pos = i;
		}
		pile = pile->next;
		i++;
	}
	return (pos);
}

void sort_four(t_node **pile_a, t_node **pile_b)
{
	int pos = find_min_pos(*pile_a);
	int size = node_size(*pile_a);
	int i = 0;

	if (pos <= size / 2)
		while (i++ < pos)
			ra(pile_a, 0);
	else
		while (i++ < size - pos)
			rra(pile_a, 0);
	pb(pile_a, pile_b);
	sort_three(pile_a);
	pa(pile_a, pile_b);
}

