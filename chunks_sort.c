/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:37:14 by saibelab          #+#    #+#             */
/*   Updated: 2025/07/11 15:35:17 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_tab(t_node *pile, int size, int *tab)
{
	int i;
	int j;
	int tmp;

	i = -1;
	while (++i < size && pile)
	{
		tab[i] = pile->value;
		pile = pile->next;
	}
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
		}
	}
}

int *sort_pile(t_node *pile, int size)
{
	int *tab;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return NULL;
	sort_tab(pile, size, tab);
	return (tab);
}

int calc_chunk_size(int total_size, int nb_chunks, int chunk_index)
{
	int	size;
	int	reste;

	size = total_size / nb_chunks;
	reste = total_size % nb_chunks;
	if (chunk_index < reste)
		return (size + 1);
	return (size);
}

void init_chunk(t_chunk *chunk, int start, int size)
{
	chunk->start = start;
	chunk->end = start + size - 1;
}

int find_value(t_node *pile_a, t_chunk *chunk, int *tab)
{
	int i;

	i = 0;
	while(pile_a)
	{
		if((pile_a->value >= tab[chunk->start]) && (pile_a->value <= tab[chunk->end]))
		{
			return (i);
		}
		i++;
		pile_a = pile_a->next;
	}
	return (-1);
}
void log_pose(t_node **pile_a, int pos)
{
	int size;
	int i;

	size = node_size(*pile_a);
	i = 0;
	if (pos <= size / 2)
	{
		while (i++ < pos)
			ra(pile_a, 0);
	}
	else
	{
		while (i++ < size - pos)
			rra(pile_a, 0);
	}
}

void log_pose_b(t_node **pile_b, int pos)
{
	int size;
	int i;

	size = node_size(*pile_b);
	i = 0;
	if (pos <= size / 2)
	{
		while (i++ < pos)
			rb(pile_b, 0);
	}
	else
	{
		while (i++ < size - pos)
			rrb(pile_b, 0);
	}
}

void init_chunks(t_chunk *chunks, int total_size, int nb_chunks)
{
	int i;
	int start;
	int size;

	start = 0;
	i = 0;
	while (i < nb_chunks)
	{
		size = calc_chunk_size(total_size, nb_chunks, i);
		init_chunk(&chunks[i], start, size);
		start += size;
		i++;
	}
}
int choose_chunk_count(int size)
{
	if (size <= 10)
		return (2);
	else if (size <= 30)
		return (3);
	else if (size <= 60)
		return (4);
	else if (size <= 100)
		return (5);
	return (5);
}


void push_chunks_to_b(t_node **pile_a, t_node **pile_b, t_chunk *chunks, int nb_chunks, int *tab)
{
	int i, pos;
	int mid;

	i = 0;
	while (i < nb_chunks)
	{
		mid = tab[chunks[i].start + (chunks[i].end - chunks[i].start) / 2];
		while (1)
		{
			pos = find_value(*pile_a, &chunks[i], tab);
			if (pos == -1)
				break;

			log_pose(pile_a, pos);

			int value = (*pile_a)->value;

			pb(pile_a, pile_b);
			if (value < mid)
				rb(pile_b, 0);
		}
		i++;
	}
}


void return_to_a(t_node **pile_a, t_node **pile_b)
{
    int pos;
    int max;

    while (*pile_b)
    {
        pos = find_max_position(*pile_b);
        log_pose_b(pile_b, pos);
        pa(pile_a, pile_b);
        max = (*pile_a)->value;
        while (*pile_b && (*pile_b)->value == max - 1)
        {
            pa(pile_a, pile_b);
            max--;
        }
    }
}


int find_max_position(t_node *pile)
{
	int max;
	int pos_max;
	int pos;
	t_node *tmp;

	max = pile->value;
	pos_max = 0;
	pos = 0;
	tmp = pile;
	while (tmp)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			pos_max = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return pos_max;
}

void chunk_sort(t_node **pile_a, t_node **pile_b)
{
	int *tab;
	int nb_chunks;
	t_chunk	*chunks;
	int size;

	size = node_size(*pile_a);
	nb_chunks = choose_chunk_count(size);
	tab = sort_pile(*pile_a, size);
	if(!tab)
		return;
	chunks = malloc(sizeof(t_chunk) * nb_chunks);
	if (!chunks)
	{
		free(tab);
		return;
	}
	init_chunks(chunks, size, nb_chunks);
	if (is_sort(*pile_a))
	{
		free(tab);
		free(chunks);
		return;
	}
	push_chunks_to_b(pile_a, pile_b, chunks, nb_chunks, tab);
	return_to_a(pile_a, pile_b);
	free(tab);
	free(chunks);
}
