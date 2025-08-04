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
