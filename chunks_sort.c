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
